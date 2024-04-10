#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[200005],mx[2005],x[200005],y[200005],pre[4005],f[4005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    n=k;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        if(x[i]<=n){
            mx[x[i]]=max(mx[x[i]],y[i]);
        }
    }
    int nm=0;
    for(int i=1;i<=n;i++)if(mx[i]){
        x[++nm]=i;
        y[nm]=mx[i];
    }
    m=nm;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=0;i<n;i++){
        f[i+1]=min(f[i+1],f[i]+a[i+1]);
        for(int j=1;j<=m;j++){
            f[i+x[j]]=min(f[i+x[j]],f[i]+pre[i+x[j]]-pre[i+y[j]]);
        }
    }
    cout<<f[n];

    return 0;
}