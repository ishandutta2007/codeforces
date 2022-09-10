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
long long d[5];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char s[8];
        scanf("%s",s);
        if(strcmp(s,"UR")==0)d[0]++;
        else if(strcmp(s,"DL")==0)d[1]++;
        else if(strcmp(s,"UL")==0)d[2]++;
        else if(strcmp(s,"DR")==0)d[3]++;
        else if(strcmp(s,"ULDR")==0)d[4]++;
    }
    long long an=(d[0]+d[1]+d[4]+1)*(d[2]+d[3]+d[4]+1);
    cout<<an<<endl;
    return 0;
}