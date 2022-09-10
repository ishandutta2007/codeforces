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
#define MOD 1000000007
char s[128];
long long two[256];
int main(){
    int i,j,k,n;
    long long an=0;
    gets(s);
    n=strlen(s);
    two[0]=1;
    for(i=1;i<256;i++)two[i]=two[i-1]*2%MOD;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            an+=two[(n-i-1)*2+i];
            an%=MOD;
        }
    }
    cout<<an<<endl;
    return 0;
}