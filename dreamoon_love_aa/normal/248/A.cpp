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
int d[2][2];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j>>k;
        d[0][j]++;
        d[1][k]++;
    }
    cout<<min(d[0][0],d[0][1])+min(d[1][0],d[1][1])<<endl;
    return 0;
}