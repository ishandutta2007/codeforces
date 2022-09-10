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
#define SIZE 200001
int a[SIZE],pos[SIZE];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    int ll=1,rr=n;
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        for(i=2;i<=mm;i++)
            if(pos[a[i]]<pos[a[i-1]])break;
        if(i>mm)ll=mm;
        else rr=mm-1;
    }
    printf("%d\n",n-ll);
    return 0;
}