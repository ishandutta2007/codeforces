#include<bits/stdc++.h>
using namespace std;
int n,v,t,mx[20][633333],mn[20][633333], hb[633333];
int Max(int l, int r){return max(mx[hb[r-l+1]][l],mx[hb[r-l+1]][r-(1<<hb[r-l+1])+1]);}
int Min(int l, int r){return min(mn[hb[r-l+1]][l],mn[hb[r-l+1]][r-(1<<hb[r-l+1])+1]);}
int main(){
    cin>>t;
    for(int i=0; i<19; ++i) for(int j=1<<i; j<1<<i+1; ++j) hb[j]=i;
    while(t--){
        cin>>n>>v;
        for(int i=1;i<=n;++i) scanf("%d",&mx[0][i]),mn[0][i]=mx[0][i];
        for(int i=1;i<19;++i) for(int j=1;j<=n;++j) mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]), mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
        int p=1, c=0;
        while(p<=n){
            //cerr<<p<<' '<<c<<endl;
            int l=p, r=n, m, a=p;
            while(m=l+r>>1,l<=r) if(Max(p,m)-Min(p,m)<=v+v) a=m, l=m+1; else r=m-1;
            c++; p=a+1; 
        }
        cout<<c-1<<endl;
    }
}