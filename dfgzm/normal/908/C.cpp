#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const int maxn=1010;
int i,j,k,n,m;
double y[maxn],x[maxn],r;
int main(){
    cin>>n>>r;
    for(i=1;i<=n;i++){
        cin>>x[i];
        double Y=r;
        for(j=1;j<i;j++){
            if(fabs(x[i]-x[j])<=r+r+eps){
                double fy=sqrt(r*r*4-fabs(x[i]-x[j])*fabs(x[i]-x[j]));
                Y=max(Y,fy+y[j]);
                // cerr<<"j="<<j<<' '<<fy<<endl;
            }
        }y[i]=Y;
        printf("%.9lf ",y[i]);
    }
}