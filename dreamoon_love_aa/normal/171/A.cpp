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
    long long x,y;
    cin>>x>>y;
    char s[12];
    sprintf(s,"%d",y);
    reverse(s,s+strlen(s));
    i=0;
    y=0;
    while(s[i]){
        y*=10;
        y+=s[i]-'0';
        i++;
    }
    printf("%I64d\n",x+y);
    return 0;
}