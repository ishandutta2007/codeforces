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
int d[3][2];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        d[x][0]+=y;
        d[x][1]+=z;
    }
    if(d[1][0]>=d[1][1])puts("LIVE");
    else puts("DEAD");
    if(d[2][0]>=d[2][1])puts("LIVE");
    else puts("DEAD");
    return 0;
}