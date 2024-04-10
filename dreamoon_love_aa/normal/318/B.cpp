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
char s[1000100];
int d[1000100];
int main(){
    int i,j,k,n;
    gets(s);
    n=strlen(s);
    for(i=0;i+5<=n;i++){
        if(strncmp("heavy",s+i,5)==0)d[i]=1;
    }
    k=0;
    long long res=0;
    for(j=n-5;j>=5;j--){
        if(strncmp("metal",s+j,5)==0)k++;
        if(d[j-5])res+=k;
    }
    cout<<res<<endl;
    return 0;
}