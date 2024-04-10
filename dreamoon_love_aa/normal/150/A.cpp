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
int d[10000000],dn;
bool win[10000000];
int main(){
    int i,j,k;
    long long n;
    cin>>n;
    for(i=2;(long long)i*i<=n;i++){
        if(n%i==0){
            d[dn++]=i;
            if(i!=n/i)d[dn++]=n/i;
        }
    }
    if(dn==0){
        puts("1\n0");
        return 0;
    }
    sort(d,d+dn);
    for(i=0;i<dn;i++){
        int cnt=0;
        for(j=0;j<i;j++){
            if(d[i]%d[j]==0){
                cnt++;
                if(!win[j]){
                    win[i]=1;
                    break;
                }
            }
        }
        if(!cnt)win[i]=1;
        if(!win[i])break;
    }
    if(i<dn){
        puts("1");
        printf("%d\n",d[i]);
    }
    else puts("2");
    return 0;
}