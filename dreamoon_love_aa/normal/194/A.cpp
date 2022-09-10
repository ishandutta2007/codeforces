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
    int i,j,k,n;
    cin>>n>>k;
    for(i=0;;i++){
        if(2*i+3*(n-i)<=k&&k<=2*i+5*(n-i)){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}