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
string s1,s2;
int main(){
    int i,j,k,n,m,an=0;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    for(i=1;i<=n&&i<=m;i++){
        if(n%i||m%i)continue;
        for(j=i;j<n;j++)
            if(s1[j]!=s1[j-i])break;
        if(j<n)continue;
        for(j=i;j<m;j++)
            if(s2[j]!=s2[j-i])break;
        if(j<m)continue;
        for(j=0;j<i;j++)
            if(s1[j]!=s2[j])break;
        if(i!=j)continue;
        an++;
    }
    cout<<an<<endl;
    return 0;
}