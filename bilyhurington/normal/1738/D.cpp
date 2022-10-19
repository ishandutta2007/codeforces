#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],b[100010];
bool check(int k){//check ans>=k
    int cntl=0,cntr=0;
    for(int i=1;i<=n;i++){
        if(b[i]>k) cntl++;
        else cntr++;
    }
    if(cntl>=k) return 1;
    else return 0;
}
void solve(int k){
    map<int,vector<int> > mp;
    map<int,int> mp2;
    for(int i=1;i<=n;i++){
        if(b[i]>k) mp[b[i]].push_back(i);
        else mp[b[i]].push_back(i);
        if(b[i]>=1&&b[i]<=n) mp2[b[b[i]]]=b[i];
    }
    int x=mp.find(0)==mp.end()?n+1:0,tot=0;
    while(mp[x].size()){
        vector<int> v=mp[x];
        for(int i=0;i<v.size();i++){
            if(v[i]==mp2[x]){
                swap(v[i],v[(int)v.size()-1]);
                break;
            }
        }
        for(auto x:v) a[++tot]=x;
        mp[x].clear();x=mp2[x];
    }
}
void solve(){
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }printf("%d\n",l);solve(l);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}