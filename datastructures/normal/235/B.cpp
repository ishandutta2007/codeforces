#include <iostream>
#include <cstdio>
using namespace std;
int n;
double p[100005],f[100005],g[100005];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i];
        f[i]=(1-p[i])*f[i-1]+p[i]*(f[i-1]+(g[i-1]+1)*(g[i-1]+1)-g[i-1]*g[i-1]);
        g[i]=(g[i-1]+1)*p[i];
    }
    printf("%.15lf\n",f[n]);
    return 0;
}