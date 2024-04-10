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
#define MOD 1000000007
long long mypow(long long x,long long y){
    long long res=1;
    x%=MOD;
    while(y){
        if(y&1){res*=x;res%=MOD;}
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
int main(){
    int i,j,k;
    long long n;
    cin>>n;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    cout<<mypow(2,n-1)*(mypow(2,n)+1)%MOD;
    return 0;
}