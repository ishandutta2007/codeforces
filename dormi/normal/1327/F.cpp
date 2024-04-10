#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
lli mod=998244353;
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
lli dp[MAXN];
int arr[MAXN];
lli pre[MAXN];
int am[MAXN];
int bit[MAXN];
lli dpsum[MAXN];
int endpoint[MAXN];
int nendpoint[MAXN];
int n,k,m;
void update(int loc){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=1;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
pair<pii,int> st[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>m;
    pre[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]*(lli)2%mod;
    }
    for(int i=0;i<m;i++){
        cin>>st[i].first.first>>st[i].first.second>>st[i].second;
    }
    lli ways=1;
    for(int b=0;b<k;b++){
        vector<pii> need;
        for(int i=1;i<=n;i++)arr[i]=0,endpoint[i]=INT_MAX,dpsum[i]=0,bit[i]=0;
        for(int i=0;i<m;i++){
            arr[st[i].first.first]+=!!(st[i].second&(1<<b));
            arr[st[i].first.second+1]-=!!(st[i].second&(1<<b));
            if((st[i].second&(1<<b))==0){
                need.push_back(st[i].first);
            }
        }
        sort(need.begin(),need.end(),[&](auto lhs, auto rhs){
            if(lhs.second==rhs.second){
                return rhs.first<lhs.first;
            }
            return lhs.second<rhs.second;
        });
        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
            am[i]=am[i-1]+!!arr[i];
        }
        vector<pii> te;
        te.push_back({0,0});
        for(auto x:need){
            if(query(x.second)-query(x.first-1)==0){
                te.push_back(x);
            }
            update(x.first);
        }
        need=te;
        for(int i=0;i<sz(need);i++){
            endpoint[need[i].second]=i;
        }
        nendpoint[n]=endpoint[n];
        for(int i=n-1;i>=1;i--){
            nendpoint[i]=min(nendpoint[i+1],endpoint[i]);
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(endpoint[i]!=INT_MAX){
                dp[i]=fix(dpsum[i-1]-dpsum[need[endpoint[i]].first-1]);
                dp[i]=fix(dp[i]+(dp[need[endpoint[i]].first-1]*fix(pre[need[nendpoint[need[endpoint[i]].first]].second-need[endpoint[i]].first+1-(am[need[nendpoint[need[endpoint[i]].first]].second]-am[need[endpoint[i]].first-1])]-1)%mod));
                if(endpoint[i]+1!=sz(need))dpsum[i]=dp[i]*fix(pre[need[endpoint[i]+1].second-i-(am[need[endpoint[i]+1].second]-am[i])]-1)%mod;
            }
            else dp[i]=dp[i-1]*(arr[i]?(lli)1:(lli)2)%mod;
            dpsum[i]=fix(dpsum[i]+dpsum[i-1]);
        }
        ways=ways*dp[n]%mod;
    }
    printf("%lli\n",ways);
    return 0;
}