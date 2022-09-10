#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,j,k,n;
    double S,a,b,c;
    cin>>S>>a>>b>>c;
    if(a+b+c<1e-9)printf("0 0 %.10lf\n",S);
    else{
        double sum=a+b+c;
        printf("%.10lf %.10lf %.10lf\n",S*a/sum,S*b/sum,S*c/sum);
    }
    return 0;
}