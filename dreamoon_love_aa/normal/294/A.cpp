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
#define SIZE 200
int a[SIZE];
int main(){
    int i,j,k,n,m,x,y;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>x>>y;
        int tmp=a[i];
        a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }
    for(i=1;i<=n;i++)cout<<a[i]<<endl;
    return 0;
}