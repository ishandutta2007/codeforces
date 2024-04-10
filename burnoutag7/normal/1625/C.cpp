#include<bits/stdc++.h>
using namespace std;

int n,k,d[505],a[505],f[505][505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d[n+1]>>k;
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(f,0x3f,sizeof(f));
    f[n+1][0]=0;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=j;k++){
                f[i][j]=min(f[i][j],f[i+k+1][j-k]+a[i]*(d[i+k+1]-d[i]));
            }
        }
    }
    cout<<*min_element(f[1],f[1]+k+1);

    return 0;
}