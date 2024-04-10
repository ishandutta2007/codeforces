#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 100000
using namespace std;
int can[1005][1005],f[1005];
int n,a[1005];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i],can[i][i]=a[i];
    for (int len=2;len<=n;len++)
        for (int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for (int k=i;k<j;k++){
                if (can[i][k]!=0&&can[k+1][j]!=0&&can[i][k]==can[k+1][j])
                    can[i][j]=can[i][k]+1;
            }
        }
    for (int i=1;i<=n;i++){
        f[i]=inf;
        for (int j=1;j<=i;j++)
            if (can[j][i]!=0)f[i]=min(f[i],1+f[j-1]);
    }
    cout<<f[n]<<endl;
}