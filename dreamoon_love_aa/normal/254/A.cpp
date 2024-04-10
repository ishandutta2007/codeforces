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
vector<int>a[5001];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=2*n;i++){
        int x;
        cin>>x;
        a[x].pb(i);
    }
    for(i=1;i<=5000;i++){
        if(a[i].size()%2)break;
    }
    if(i<=5000){
        puts("-1");
        return 0;
    }
    for(i=1;i<=5000;i++){
        for(j=0;j<a[i].size();j+=2)printf("%d %d\n",a[i][j],a[i][j+1]);
    }
    return 0;
}