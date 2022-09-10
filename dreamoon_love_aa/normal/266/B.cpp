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
char s[64];
int main(){
    int i,j,k,n,t;
    scanf("%d%d",&n,&t);
    scanf("%s",s);
    for(i=0;i<t;i++){
        vector<int>d;
        for(j=0;j<n-1;j++)
            if(s[j]=='B'&&s[j+1]=='G')d.pb(j);
        for(j=0;j<d.size();j++)
            swap(s[d[j]],s[d[j]+1]);
    }
    puts(s);
    return 0;
}