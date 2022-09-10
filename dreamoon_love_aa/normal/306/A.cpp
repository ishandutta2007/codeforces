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
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
        cout<<n/m+1-(i>=n%m)<<" ";
    return 0;
}