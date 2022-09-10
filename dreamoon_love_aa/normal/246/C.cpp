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
#define SIZE 55
int a[SIZE],now;
vector<int>an[SIZE*SIZE*SIZE];
int main(){
    int i,j,k,n,K;
    cin>>n>>K;
    for(i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)an[now++].pb(a[i]);
    for(i=n;i>1;i--){
        for(k=1;k<i;k++){
            for(j=i;j<=n;j++)an[now].pb(a[j]);
            an[now].pb(a[k]);
            now++;
        }
    }
    for(i=0;i<K;i++){
        printf("%d",an[i].size());
        for(j=0;j<an[i].size();j++)printf(" %d",an[i][j]);
        puts("");
    }
    return 0;
}