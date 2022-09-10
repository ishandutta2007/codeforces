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
#define SIZE 1111
int a[SIZE],r1,r2,r3;
int main(){
    int i,j,k,n,x,mm,an=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    mm=(n+1)/2;
    while(a[mm-1]!=x){
        a[n++]=x;
        sort(a,a+n);
        mm=(n+1)/2;
        an++;
    }
    printf("%d\n",an);
    return 0;
}