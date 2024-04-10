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
long long p,d;
long long an1,an2;
int nine(long long x){
    int res=0;
    while(x){
        if(x%10==9)res++;
        else return res;
        x/=10;
    }
    return res;
}
void test(long long x){
    if(x>p||x<p-d)return;
    int nn=nine(x);
    if(nn>an2||(nn==an2&&x>an1)){
        an1=x;
        an2=nn;
    }
}
int main(){
    int j,k,n;
    cin>>p>>d;
    an1=p;
    an2=nine(p);
    for(long long i=10;i<=p;i*=10){
        test(p-p%i+i-1);
        test(p-p%i-1);
        if(i==p)break;
    }
    cout<<an1<<endl;
    return 0;
}