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
int d[1001];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        d[x]++;
    }
    for(i=1;i<=1000;i++)
        if(d[i]>(n+1)/2)break;
    if(i<=1000)puts("NO");
    else puts("YES");
    return 0;
}