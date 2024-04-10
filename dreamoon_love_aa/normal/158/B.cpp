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
int d[5];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        d[k]++;
    }
    an=d[4];
    an+=d[3];
    d[1]=max(0,d[1]-d[3]);
    an+=d[2]/2;
    d[2]%=2;
    if(d[2]){
        an++;
        d[1]=max(0,d[1]-2);
    }
    an+=(d[1]+3)/4;
    cout<<an<<endl;
    return 0;
}