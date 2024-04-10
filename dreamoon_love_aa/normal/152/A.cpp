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
char s[122][122];
int main(){
    int i,j,k,n,m,an=0;
    cin>>n>>m;
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<n;k++)
                if(s[i][j]<s[k][j])break;
            if(k==n)break;
        }
        if(j<m)an++;
    }
    cout<<an<<endl;
    return 0;
}