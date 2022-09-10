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
int d[1000000];
int main(){
    int i,j,k,n,a,b;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)cin>>d[i];
    sort(d,d+n);
    cout<<d[b]-d[b-1]<<endl;
    return 0;
}