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
#define SIZE 1000000
bitset<SIZE>p;
int a[512][512];
int f(int x){
    int res=0;
    while(p[x]){
        res++;
        x++;
    }
    return res;
}
int main(){
    int i,j,k,n,m;
    p[1]=1;
    for(i=2;i<SIZE;i++)
        if(!p[i])
            for(j=i+i;j<SIZE;j+=i)p[j]=1;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]=f(a[i][j]);
        }
    int an=1000000000;
    for(i=0;i<n;i++){
        int cnt=0;
        for(j=0;j<m;j++)cnt+=a[i][j];
        an=min(an,cnt);
    }
    for(i=0;i<m;i++){
        int cnt=0;
        for(j=0;j<n;j++)cnt+=a[j][i];
        an=min(an,cnt);
    }
    printf("%d\n",an);
    return 0;
}