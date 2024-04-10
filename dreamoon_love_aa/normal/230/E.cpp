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
long long deg[1000100];
long long f(long long x){return x*(x-1)*(x-2)/6;}
int main(){
    int i,j,k;
    long long n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++;
        deg[y]++;
    }
    long long res=0;
    for(i=1;i<=n;i++){
        res-=deg[i]*(n-1-deg[i]);
    }
    res/=2;
    res+=f(n);
    cout<<res<<endl;
    return 0;
}