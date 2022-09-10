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
    cin>>n;
    while(n--){
        cin>>k;
        printf("%I64d\n",4ll*k/__gcd(4ll*k,k+1ll)+1);
    }
    return 0;
}