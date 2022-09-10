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
int a,b;
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
bool ex(int x){
    while(x){
        int tmp=x%10;
        if(tmp!=a&&tmp!=b)return 0;
        x/=10;
    }
    return 1;
}
int main(){
    int i,j,k,n;
    cin>>a>>b>>n;
    long long v=1,res=0;
    for(i=0;i<=n;i++){
        int now=a*i+b*(n-i);
        if(ex(now))res+=v;
        v=v*(n-i)%MOD;
        v=v*mypow(i+1,MOD-2)%MOD;
    }
    cout<<res%MOD<<endl;
    return 0;
}