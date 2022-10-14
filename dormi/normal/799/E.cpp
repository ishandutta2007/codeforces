#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=200000+1;
lli prices[MAXN];
int type[MAXN];
vector<lli> both;
vector<lli> ar,ma;
vector<lli> neither;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>prices[i];
    }
    int a;
    cin>>a;
    int x;
    for(int i=0;i<a;i++){
        cin>>x;
        type[x]+=1;
    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++){
        cin>>x;
        type[x]+=2;
    }
    if(a<k||b<k||k>m){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(type[i]==0){
            neither.push_back(prices[i]);
        }
        else if(type[i]==1){
            ar.push_back(prices[i]);
        }
        else if(type[i]==2){
            ma.push_back(prices[i]);
        }
        else{
            both.push_back(prices[i]);
        }
    }
    sort(both.begin(),both.end());
    while(sz(both)>k)neither.push_back(both.back()),both.pop_back();
    sort(neither.begin(),neither.end());
    sort(ar.begin(),ar.end());
    sort(ma.begin(),ma.end());
    lli ans=LLONG_MAX;
    lli cur=0;
    int miam=min(k,min(sz(ar),min(sz(ma),m/2)));
    multiset<lli> canuse;
    int am=sz(neither)+sz(ar)-(miam)+sz(ma)-(miam);
    while(miam>=0&&(am<m-(miam*2+k-miam)||2*miam+k-miam>m)){
        miam--;
        am+=2;
    }
    if(miam<0){
        printf("-1\n");
        return 0;
    }
    if(k-miam>sz(both)){
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<miam;i++)cur+=ar[i]+ma[i];
    for(int i=miam;i<sz(ar);i++)canuse.insert(ar[i]);
    for(int i=miam;i<sz(ma);i++)canuse.insert(ma[i]);
    for(lli y:neither)canuse.insert(y);
    multiset<lli> used;
    for(int i=0;i<m-(miam*2+k-miam);i++) {
        used.insert(*canuse.begin());
        cur+=*canuse.begin();
        canuse.erase(canuse.begin());
    }
    for(int i=0;i<k-miam;i++){
        cur+=both[i];
    }
    ans=cur;
    for(int i=miam-1;i>=0;i--){
        cur-=ar[i];
        cur-=ma[i];
        if(k-i-1>=sz(both))break;
        cur+=both[k-i-1];
        int newed=0;
        if(sz(used)&&ar[i]<=*used.rbegin())newed+=1,used.insert(ar[i]),cur+=ar[i];
        else canuse.insert(ar[i]);
        if(sz(used)&&ma[i]<=*used.rbegin())newed+=1,used.insert(ma[i]),cur+=ma[i];
        else canuse.insert(ma[i]);
        if(newed==0){
            used.insert(*canuse.begin());
            cur+=*canuse.begin();
            canuse.erase(canuse.begin());
        }
        else if(newed==2){
            cur-=*used.rbegin();
            canuse.insert(*used.rbegin());
            used.erase(used.find(*used.rbegin()));
        }
        ans=min(ans,cur);
    }
    if(ans==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}