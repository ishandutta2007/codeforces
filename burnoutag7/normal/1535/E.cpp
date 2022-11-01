#include<bits/stdc++.h>
using namespace std;

int n,q,a[300005],c[300005],fa[300005][19],mp[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    n=1;
    cin>>q>>a[1]>>c[1];
    memset(fa[1],-1,sizeof(fa[1]));
    mp[0]=1;
    for(int cq=1;cq<=q;cq++){
        int typ,x,y,z;
        cin>>typ>>x>>y;
        x=mp[x];
        if(typ==1){
            cin>>z;
            mp[cq]=++n;
            fa[n][0]=x;
            a[n]=y;
            c[n]=z;
            for(int i=0;i<18;i++){
                fa[n][i+1]=fa[n][i]==-1?-1:fa[fa[n][i]][i];
            }
        }else{
            int b=0;
            long long m=0;
            while(a[x]&&b<y){
                int p=x;
                for(int i=18;i>=0;i--){
                    int &fapi=fa[p][i];
                    if(fapi!=-1&&a[fapi]){
                        p=fapi;
                    }
                }
                if(a[p]+b>y){
                    a[p]-=y-b;
                    m+=(long long)c[p]*(y-b);
                    b=y;
                }else{
                    m+=(long long)c[p]*a[p];
                    b+=a[p];
                    a[p]=0;
                }
            }
            cout<<b<<' '<<m<<endl;
        }
    }

    return 0;
}