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
int n,m,a[100010];
bool compare(int x,int y){
    if(abs(m+1-2*x)==abs(m+1-2*y))return x<y;
    else return abs(m+1-2*x)<abs(m+1-2*y);
}
int main(){
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=m;i++)a[i-1]=i;
    sort(a,a+m,compare);
    for(i=0;i<n;i++)printf("%d\n",a[i%m]);
    return 0;
}