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
int a[1111];
void f(int x){
    if(x==1)return;
    swap(a[x-1],a[x]);
    f(x-1);
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)a[i]=i;
    f(n);
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",a[i]);
    }
    return 0;
}