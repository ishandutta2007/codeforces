#include<bits/stdc++.h>
using namespace std;

int n,a[300005],f[300005][31];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]/=100;
    }
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(j+a[i]<=30){
                f[i][j]=min(f[i][j],f[i-1][j+a[i]]);
            }
            if(j>=a[i]/10){
                f[i][j]=min(f[i][j],f[i-1][j-a[i]/10]+a[i]);
            }
            if(j<=a[i]){
                f[i][0]=min(f[i][0],f[i-1][j]+a[i]-j);
            }
        }
    }
    cout<<*min_element(f[n],f[n]+31)*100;

    return 0;
}