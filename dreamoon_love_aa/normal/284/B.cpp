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
int d[3];
char s[1000001];
int main(){
    int i,j,k,n;
    cin>>n;
    scanf("%s",s);
    for(i=0;i<n;i++){
        if(s[i]=='A')d[0]++;
        else if(s[i]=='F')d[1]++;
        else d[2]++;
    }
    if(d[2]>1)puts("0");
    else if(d[2]==1)puts("1");
    else printf("%d\n",d[0]);
    return 0;
}