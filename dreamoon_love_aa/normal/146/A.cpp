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
    int i,j=0,k=0,n;
    string str;
    cin>>n>>str;
    for(i=0;i<n;i++){
        if(str[i]!='4'&&str[i]!='7')break;
    }
    if(i<n){
        puts("NO");
        return 0;
    }
    for(i=1;i*2<=n;i++){
        j+=str[i-1];
        k+=str[i-1+n/2];
    }
    puts(j==k?"YES":"NO");
    return 0;
}