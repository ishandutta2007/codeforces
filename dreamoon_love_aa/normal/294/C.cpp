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
#define SIZE 1024
#define MOD 1000000007
long long dp[SIZE];
int d[SIZE];
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
int main(){
    int i,j,k,n,m,now=0,sum=0;
    long long an=1;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>k;
        d[k]=1;
    }
    dp[now]=1;
    vector<int>ha;
    for(i=1;i<=n;i=j){
        if(d[i]==0){
            for(j=i+1;j<=n&&d[j]==0;j++);
            ha.pb(j-i);
            sum+=ha.back();
        }
        else j=i+1;
    }
    for(i=1;i<=sum;i++)an=an*i%MOD;
    for(i=0;i<ha.size();i++){
        for(j=1;j<=ha[i];j++)an=an*mypow(j,MOD-2)%MOD;
    }
    for(i=1;d[i]==0;i++);
    for(;i<=n;i=j){
        if(d[i]==0){
            for(j=i+1;j<=n&&d[j]==0;j++);
            if(j<=n)an=an*mypow(2,j-i-1)%MOD;
        }
        else j=i+1;
    }
    cout<<an<<endl;
    return 0;
}