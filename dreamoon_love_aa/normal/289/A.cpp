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
    cin>>n>>i;
    while(n--){
        cin>>j>>k;
        res+=k-j+1;
    }
    if(res%i==0)cout<<0<<endl;
    else cout<<i-res%i<<endl;
    return 0;
}