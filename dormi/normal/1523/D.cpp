#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int dp[(1<<15)];
vector<int> exactly[MN];
int ind[61];
bool res[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(int(0), int(n-1));
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<m;j++){
            if(a[j]=='1')exactly[i].push_back(j);
        }
    }
    int ma=0;
    int needed=(n+1)/2;
    vector<int> ans;
    for(int i=0;i<64;i++){
        int cur=dis(gen);
        for(int j=0;j<m;j++)ind[j]=-1;
        for(int j=0;j<(1<<p);j++)dp[j]=0;
        int curind=0;
        for(auto x:exactly[cur]){
            ind[x]=curind;
            curind++;
        }
        for(int j=0;j<n;j++){
            int val=0;
            for(auto x:exactly[j]){
                if(ind[x]!=-1){
                    val+=(1<<ind[x]);
                }
            }
            dp[(1<<p)-1-val]++;
        }
        for(int j=0;j<p;j++){
            for(int k=0;k<(1<<p);k++){
                if(k&(1<<j))dp[k]+=dp[k-(1<<j)];
            }
        }
        for(int j=0;j<(1<<p);j++){
            if(dp[j]>=needed){
                if(p-__builtin_popcount(j)>=ma){
                    ma=p-__builtin_popcount(j);
                    ans=vector<int>();
                    for(int k=0;k<p;k++){
                        if(!(j&(1<<k))){
                            ans.push_back(exactly[cur][k]);
                        }
                    }
                }
            }
        }
    }
    for(auto x:ans){
        res[x]=true;
    }
    for(int i=0;i<m;i++){
        if(res[i])printf("1");
        else printf("0");
    }
    return 0;
}