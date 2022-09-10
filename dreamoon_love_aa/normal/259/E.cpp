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
#define SIZE 100010
#define MOD 1000000007
int a[SIZE];
vector<int>f[SIZE];
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
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=100000;i++){
        for(j=i;j<=100000;j+=i){
            f[j].pb(i);
        }
    }
    sort(a+1,a+1+n);
    int now=1;
    long long an=1;
    for(i=2;i<=a[n];i++){
        while(now<=n&&i>a[now])now++;
        long long res=mypow((int)f[i].size(),n-now+1)-mypow((int)f[i].size()-1,n-now+1);
        while(res<0)res+=MOD;
        int ll=1;
        for(j=1;j<f[i].size();j++){
            int rr=lower_bound(a+ll,a+n+1,f[i][j])-a;
            res=res*mypow(j,rr-ll)%MOD;
            ll=rr;
        }
        an+=res;
    }
    an%=MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}