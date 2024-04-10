#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define ll long long 
#define ri int
int n,i;
double p;
const double eps=1e-10;
int main(){
    scanf("%d%lf",&n,&p);
    for(i=0;i<n;i++){
        double tot=1.0*n*(n-1)*(n-2)/6;
        double P=1.0*(n-i)*(n-i-1)*(n-i-2)/6;
        P+=0.5*(n-i)*(n-i-1)/2*i;
        P/=tot;
        if(1.0-P+eps>p) break;
    }
    printf("%d\n",i);
}