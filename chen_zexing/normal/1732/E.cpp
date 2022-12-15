#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int bl=140;
int a[50005],b[50005];
int type[405],belong[50005],st[405],ed[405];
vector <int> fac[50005];
int f[50005];
long long mn[405][50005],ans[405];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        for(int i=2;i<=50000;i++){
            if(!f[i])
                for(int j=i;j<=50000;j+=i) fac[j].push_back(i),f[j]=1;
        }
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),belong[i]=(i-1)/bl+1;
        for(int i=1;i<=belong[n];i++)
            for(int j=1;j<=50000;j++)
                mn[i][j]=LLONG_MAX;
        for(int i=1;i<=belong[n];i++) ans[i]=LLONG_MAX;
        for(int i=1;i<=belong[n];i++) st[i]=(i-1)*bl+1,ed[i]=min(n,i*bl);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            for(int j=1;j*j<=b[i];j++)
                if(b[i]%j==0){
                    mn[belong[i]][j]=min(mn[belong[i]][j],(long long)b[i]/j);
                    mn[belong[i]][b[i]/j]=min(mn[belong[i]][b[i]/j],(long long)j);
                }
        }
        for(int i=1;i<=n;i++) ans[belong[i]]=min(ans[belong[i]],1LL*a[i]*b[i]/gcd(a[i],b[i])/gcd(a[i],b[i]));
        for(int i=1;i<=belong[n];i++)
            for(int j=1;j<=50000;j++)
                for(auto t:fac[j])
                    mn[i][j]=min(mn[i][j],mn[i][j/t]*t);
        for(int i=1,t,l,r,v;i<=q;i++){
            scanf("%d%d%d",&t,&l,&r);
            if(t==1){
                scanf("%d",&v);
                if(belong[l]==belong[r]){
                    ans[belong[l]]=LLONG_MAX;
                    if(type[belong[l]]){
                        for(int j=st[belong[l]];j<l;j++) a[j]=type[belong[l]];
                        for(int j=r+1;j<=ed[belong[l]];j++) a[j]=type[belong[l]];
                        type[belong[l]]=0;
                    }
                    for(int j=l;j<=r;j++) a[j]=v;
                    for(int j=st[belong[l]],g;j<=ed[belong[l]];j++){
                        g=gcd(a[j],b[j]);
                        ans[belong[l]]=min(ans[belong[l]],1LL*a[j]*b[j]/g/g);
                    }
                }
                else{
                    ans[belong[l]]=LLONG_MAX;
                    if(type[belong[l]]){
                        for(int j=st[belong[l]];j<l;j++) a[j]=type[belong[l]];
                        type[belong[l]]=0;
                    }
                    for(int j=l;j<=ed[belong[l]];j++) a[j]=v;
                    for(int j=st[belong[l]],g;j<=ed[belong[l]];j++){
                        g=gcd(a[j],b[j]);
                        ans[belong[l]]=min(ans[belong[l]],1LL*a[j]*b[j]/g/g);
                    }
                    ans[belong[r]]=LLONG_MAX;
                    if(type[belong[r]]){
                        for(int j=r+1;j<=ed[belong[r]];j++) a[j]=type[belong[r]];
                        type[belong[r]]=0;
                    }
                    for(int j=st[belong[r]];j<=r;j++) a[j]=v;
                    for(int j=st[belong[r]],g;j<=ed[belong[r]];j++){
                        g=gcd(a[j],b[j]);
                        ans[belong[r]]=min(ans[belong[r]],1LL*a[j]*b[j]/g/g);
                    }
                    for(int j=belong[l]+1;j<belong[r];j++) type[j]=v,ans[j]=mn[j][v];
                }
            }
            else{
                if(belong[l]==belong[r]){
                    long long aans=LLONG_MAX;
                    for(int j=l,g;j<=r;j++){
                        if(type[belong[l]]) a[j]=type[belong[l]];
                        g=gcd(a[j],b[j]);
                        aans=min(aans,1LL*a[j]*b[j]/g/g);
                    }
                    printf("%lld\n",aans);
                }
                else{
                    long long aans=LLONG_MAX;
                    for(int j=l,g;j<=ed[belong[l]];j++){
                        if(type[belong[l]]) a[j]=type[belong[l]];
                        g=gcd(a[j],b[j]);
                        aans=min(aans,1LL*a[j]*b[j]/g/g);
                    }
                    for(int j=st[belong[r]],g;j<=r;j++){
                        if(type[belong[r]]) a[j]=type[belong[r]];
                        g=gcd(a[j],b[j]);
                        aans=min(aans,1LL*a[j]*b[j]/g/g);
                    }
                    for(int j=belong[l]+1;j<belong[r];j++) aans=min(aans,ans[j]);
                    printf("%lld\n",aans);
                }
            }
        }
    }
    return 0;
}