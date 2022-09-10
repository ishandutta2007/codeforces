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
long long d[1000002],a[100001],an[1000002];
void insert(int x,long long v){
    v%=MOD;
    if(v<0)v+=MOD;
    while(x<1000002){
        d[x]+=v;
        if(d[x]>=MOD)d[x]-=MOD;
        x+=x&-x;
    }
}
long long qq(int x){
    long long res=0;
    while(x){
        res+=d[x];
        if(res>=MOD)res-=MOD;
        x-=x&-x;
    }
    return res;
}
int main(){
    int i,j,k,n;
    long long res=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    insert(1,1);
    for(i=1;i<=n;i++){
        long long tmp=qq(a[i]+1);
        {
            tmp-=an[a[i]];
            if(tmp<0)tmp+=MOD;
        }
        an[a[i]]+=tmp;
        if(an[a[i]]>=MOD)an[a[i]]-=MOD;
        res+=tmp*a[i]%MOD;
        if(res>=MOD)res-=MOD;
        insert(a[i]+1,tmp*a[i]);
    }
    cout<<res<<endl;
    return 0;
}