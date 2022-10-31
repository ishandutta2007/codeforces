#include <bits/stdc++.h>
using namespace std;

long long   a[5][5],sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8;
int main(){
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        cin>>a[i][j];
    for (int i=1;i<=100001;++i){
        sum1=i+a[1][2]+a[1][3];
        sum2=i+a[2][1]+a[3][1];
        long long k=sum1-a[1][2]-a[3][2];
        sum3=a[1][2]+k+a[3][2];
        sum4=a[2][1]+k+a[2][3];
        long long z=sum1-a[1][3]-a[2][3];
        sum5=a[1][3]+a[2][3]+z;
        sum6=a[3][1]+a[3][2]+z;
        sum7=i+k+z;
        sum8=k+a[1][3]+a[3][1];
        if (sum2!=sum1 || sum3!=sum1 || sum4!=sum1 || sum5!=sum1 || sum6!=sum1 || sum7!=sum1 || sum8!=sum1 || k<=0 || z<=0) continue;
        a[1][1]=i;
        a[2][2]=k;
        a[3][3]=z;
        for (int i=1;i<=3;++i){
            for (int j=1;j<=3;++j)
            cout<<a[i][j]<<" ";
            cout<<'\n';
        }
        return 0;
    }
}