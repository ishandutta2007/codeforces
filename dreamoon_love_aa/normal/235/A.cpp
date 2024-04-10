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
long long lcm(long long x,long long y){
    return x/__gcd(x,y)*y;
}
long long lcm(long long x,long long y,long long z){
    return lcm(lcm(x,y),z);
}
int main(){
    int i,j,k;
    long long n;
    cin>>n;
    if(n==1)puts("1");
    else if(n==2)puts("2");
    else if(n&1){
        cout<<n*(n-1)*(n-2)<<endl;
    }
    else{
        long long an=(n-1)*(n-2)*(n-3);
        for(i=n-1;i>=1&&n*i*(i-1)>an;i--){
            for(j=i-1;j>0&&n*i*j>an;j--){
                an=max(an,lcm(n,i,j));
            }
        }
        cout<<an<<endl;
    }
    return 0;
}