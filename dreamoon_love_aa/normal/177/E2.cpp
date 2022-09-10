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
long long a[11111],b[11111],c,ma;
int n;
#define MAX 2000000000000000000ll
long long f(long long x){
    int i;
    long long ll=0,rr=ma;
    long long now;
    while(ll<rr){
        long long mm=(ll+rr+1)>>1;
        now=n;
        for(i=0;i<n;i++){
            now+=(mm*a[i])/b[i];
            if(now>=x)break;
        }
        if(i<n)rr=mm-1;
        else ll=mm;
    }
    return ll;
}
int main(){
    int i,j,k;
    long long c;
    cin>>n>>c;
    ma=MAX+1;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(a[i])ma=min(ma,MAX/a[i]);
    }
    if(ma==MAX+1){
        if(c==n)puts("-1");
        else puts("0");
        return 0;
    }
    if(c<n){
        puts("0");
        return 0;
    }
    cout<<f(c+1)-f(c)<<endl;
    return 0;
}