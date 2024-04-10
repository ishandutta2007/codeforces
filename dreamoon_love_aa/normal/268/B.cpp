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
    int i,j,k,n,res=0;
    cin>>n;
    res=n;
    for(i=1;i<n;i++)
        res+=(n-i)*i;
    cout<<res<<endl;
    return 0;
}