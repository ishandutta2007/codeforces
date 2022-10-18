#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;

int n;
int a[maxn][maxn];
int p[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
        int ci=i,cj=i;
        for(int j=1;j<=p[i];){
            for(;cj>=1&&!a[ci][cj];cj--,j++){
                if(j>p[i]){
                    cout<< -1;
                    return 0;
                }
                a[ci][cj]=p[i];
            }
            cj++;
            ci++;
            if(j>p[i])break;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)cout<<a[i][j]<<" \n"[j==i];
    return 0;
}