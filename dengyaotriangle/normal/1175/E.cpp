#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
const int maxl=24;
const int maxd=500005;

struct seg{
    int l,r;
};
int n,m;
seg s[maxn],q[maxn];
int fa[maxd][maxl];
int pw2[maxl ];
int pfm[maxn];

bool cmp(seg a,seg b){
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
int main(){
    pw2[0]=1;for(int i=1;i<maxl;i++) pw2[i]=pw2[i-1]*2;
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].l>>s[i].r;
    }   
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
    }
    sort(s+1,s+1+n,cmp);
    pfm[0]=-1;
    for(int i=1;i<=n;i++){
        pfm[i]=max(pfm[i-1],s[i].r);
    }
    int p2=0;
    for(int i=0;i<maxd;i++){
        while(p2!=n){
            if(s[p2+1].l<=i)p2++;
            else break;
        }
        if(pfm[p2]<=i) fa[i][0]=-1;
        else fa[i][0]=pfm[p2];
    }
    for(int i=1;i<maxl;i++){
        for(int j=0;j<maxd;j++){
            fa[j][i]=fa[j][i-1];
            if(fa[j][i]!=-1) fa[j][i]=fa[fa[j][i]][i-1];

        }
    }
    for(int i=1;i<=m;i++){
        int cur=q[i].l,ans=0;
        for(int j=maxl-1;j>=0;j--){
            if(fa[cur][j]!=-1){
                if(fa[cur][j]<q[i].r){
                    ans+=pw2[j];
                    cur=fa[cur][j];
                }
            }
        }
        if(fa[cur][0]<q[i].r){
            cout<<-1<<'\n';
        }else{
            cout<<ans+1<<'\n';
        }
    }
    return 0;
}//qwq