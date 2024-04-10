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
int d[2000001];
int main(){
    long long res=0;
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&d[i]);
    sort(d,d+n);
    reverse(d,d+n);
    for(i=1;i<=n;i<<=2){
        for(j=0;j<i;j++)res+=d[j];
    }
    cout<<res<<endl;
    return 0;
}