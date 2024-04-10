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
    int i,j,k,n,m,cnt=0;
    cin>>n>>m;
    for(i=0;i<=1000;i++)
        for(j=0;j<=1000;j++)
            if(i*i+j==n&&i+j*j==m)cnt++;
    cout<<cnt<<endl;
    return 0;
}