#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[1234],q[1234],ind[1234];
vector<int>v[1222];
#define mod 998244353
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1,x,y;i<=m;++i) cin>>x>>y, v[x].push_back(y), ind[y]++;
        int ans=0;
        while(ans<n){
            int t=0;
            for(int i=1;i<=n;++i) if(a[i]) q[++t]=i;
            if(t==0) break;
            for(int i=1;i<=t;++i){
                a[q[i]]--;
                for(auto x:v[q[i]]) a[x]++;
            }
            ans++;
        }
        int t=0;
        if(ans<n) {printf("%d\n",ans); goto xxx;}
        for(int i=1;i<=n;++i) if(!ind[i]) q[++t]=i;
        for(int h=1;h<=t;++h){
            //cerr<<"!!!"<<h<<endl;
            int x=q[h];
            if(h==n) printf("%d\n", (a[x]+n)%mod);
            for(auto y:v[x]){
                (a[y]+=a[x])%=mod;
                ind[y]--;
                if(!ind[y]) q[++t]=y;
            }
        }
        xxx:
        for(int i=1;i<=n;++i) v[i].clear(), ind[i]=0;
    }
}