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
#define SIZE 10000010
bool sq[SIZE];
int fac[SIZE];
int main(){
    int i,j,k,n,a;
    for(i=1;i<=10000000;i++){
        if((long long)i*i<SIZE)sq[i*i]=1;
        if(sq[i])
            for(j=i;j<SIZE;j+=i)fac[j]=i;
    }
    cin>>a>>n;
    long long an=0;
    for(i=0;i<n;i++)an+=(a+i)/fac[a+i];
    cout<<an<<endl;
    return 0;
}