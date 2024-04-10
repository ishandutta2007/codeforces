#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1200010;
int i,j,k,n,m,a[maxn],id[maxn],cnt,Fa[maxn];
set<pair<int,int>>S;
int find(int x){
    return Fa[x]==x?x:Fa[x]=find(Fa[x]);
}
signed main(){
    for(i=1;i<maxn;i++)Fa[i]=i;
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    cin>>m;
    S.insert(make_pair(1000000000,-1));
    for(i=1;i<=n;i++){
        id[++cnt]=a[i];
        S.insert(make_pair(a[i],cnt));
        a[i]=cnt;
    }
    for(i=1;i<=m;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,w;
            scanf("%d%d",&x,&w);
            id[++cnt]=w;
            S.insert(make_pair(w,cnt));
            a[x]=cnt;
        }else
        if(op==2){
            int x;
            scanf("%d",&x);
            printf("%d\n",id[find(a[x])]);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            id[++cnt]=l-1;
            id[++cnt]=r+1;
            while((*S.lower_bound(make_pair(l,-1))).first<=r){
                auto t=*S.lower_bound(make_pair(l,-1));
                S.erase(S.find(t));
                if(t.first<=(l+r)/2)Fa[find(t.second)]=cnt-1;
                else Fa[find(t.second)]=cnt;
            }
            S.insert(make_pair(l-1,cnt-1));
            S.insert(make_pair(r+1,cnt));
        }
    }
}