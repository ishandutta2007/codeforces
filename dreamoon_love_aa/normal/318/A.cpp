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
    int i,j;
    long long k,n;
    cin>>n>>k;
    if(k<=(n+1)/2)cout<<k*2-1<<endl;
    else{
        k-=(n+1)/2;
        cout<<k*2<<endl;
    }
    return 0;
}