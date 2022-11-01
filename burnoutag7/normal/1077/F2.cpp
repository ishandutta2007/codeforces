#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,x,a[5005],q[5005],h,t;
ll f[5005][5005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k*x+k<=n){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=k;i++)f[i][1]=a[i];
    for(int j=2;j<=x;j++){
        h=t=0;
        int p=j-1;
        for(int i=j;i<=min(n,j*k);i++){
            while(p<i){
                while(h<t&&f[q[t-1]][j-1]<f[p][j-1])t--;
                q[t++]=p;
                p++;
            }
            while(h<t&&q[h]+k<i)h++;
            f[i][j]=f[q[h]][j-1]+a[i];
        }
    }
    ll ans=0;
    for(int i=max(x,n-k+1);i<=n;i++)ans=max(ans,f[i][x]);
    cout<<ans;

    return 0;
}