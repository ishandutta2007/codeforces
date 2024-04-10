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
#define MAX 1000000000
int a[30000],an,n,d[30000];
void go(int x){
    int y=n/x,i;
    for(i=1;i<=y;i++)d[i]=a[i];
    for(;i<=n;i++)d[i]=a[i]+d[i-y];
    for(i=0;i<y;i++)an=max(an,d[n-i]);
}
int main(){
    int i,j,k;
    an=-MAX;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=3;i<=n;i++)
        if(n%i==0){
            go(i);
        }
    cout<<an<<endl;
    return 0;
}