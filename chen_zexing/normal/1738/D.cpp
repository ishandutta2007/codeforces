#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int b[100005],ans[100005];
vector <int> v[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,x=0;
        scanf("%d",&n);
        int l=0,r=n,st=-1;
        map <int,int> mp;
        for(int i=0;i<=n+1;i++) v[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),mp[b[i]]=1,v[b[i]].push_back(i);
        vector <int> tmp;
        for(int i=1;i<=n;i++){
            if(b[i]==n+1||b[i]==0) tmp.push_back(i);
            if(b[i]==n+1) st=0;
            else if(b[i]==0) st=1;
        }
        while(x<n){
            int sp=-1;
            for(auto t:tmp) if(mp[t]) sp=t;
            if(st==0) for(auto t:tmp) l=max(l,t);
            else for(auto t:tmp) r=min(r-1,t);
            if(sp==-1) break;
            for(auto t:tmp) if(t!=sp) ans[++x]=t;
            ans[++x]=sp;
            st^=1;
            tmp.clear();
            for(auto t:v[sp]) tmp.push_back(t);
        }
        for(auto t:tmp) ans[++x]=t;
        printf("%d\n",l);
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}