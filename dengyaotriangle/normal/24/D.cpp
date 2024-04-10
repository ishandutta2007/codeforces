#include<bits/stdc++.h>
//dengyaotriangle
using namespace std;

const int maxn=1005;

int n,m;
int x,y;

double a[maxn][maxn];
double ans[maxn];

int main(){
    cin>>n>>m>>x>>y;
    if(x==n){
        cout<<"0.0000000";
        return 0;
    }
    for(int i=n-1;i>=x;i--){
        if(m==1){
            a[1][1]=1.0/2;
            a[1][m+1]=1+1.0/2*ans[1];
        }else{
            a[1][1]=a[m][m]=2.0/3;
            a[1][2]=a[m][m-1]=-1.0/3;
            a[1][m+1]=1.0+1.0/3*ans[1];
            a[m][m+1]=1.0+1.0/3*ans[m];
            for(int j=2;j<m;j++){
                a[j][j]=3.0/4;
                a[j][j-1]=a[j][j+1]=-1.0/4;
                a[j][m+1]=1.0+1.0/4*ans[j];
            }
        }
        for(int i=1;i<m;i++){
            a[i+1][i+1]-=a[i+1][i]/a[i][i]*a[i][i+1];
            a[i+1][m+1]-=a[i+1][i]/a[i][i]*a[i][m+1];
        }
        for(int i=m;i>1;i--){
            a[i-1][m+1]-=a[i-1][i]/a[i][i]*a[i][m+1];
        }
        for(int i=1;i<=m;i++)ans[i]=a[i][m+1]/a[i][i];
        if(i==x)cout<<fixed<<setprecision(10)<<ans[y];
    }
    return 0;
}