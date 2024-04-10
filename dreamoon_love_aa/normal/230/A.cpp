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
vector<int>d[10001];
int main(){
    int i,j,k=0,n,s;
    cin>>s>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        d[x].pb(y);
    }
    for(i=1;i<=10000&&i<s;i++){
        for(j=0;j<d[i].size();j++){s+=d[i][j];k++;}
    }
    if(k==n)puts("YES");
    else puts("NO");
    return 0;
}