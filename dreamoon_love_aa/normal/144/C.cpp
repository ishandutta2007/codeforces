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
string s,p;
int d[26],r[26];
int main(){
    int i,j,k,n,m,an=0;
    cin>>s>>p;
    n=s.size();
    m=p.size();
    if(n<m){
        puts("0");
        return 0;
    }
    for(i=0;i<m;i++)r[p[i]-'a']++;
    for(i=0;i<m;i++)d[s[i]-'a']++;
    for(i=0;i<26;i++)
        if(d[i]>r[i])break;
    if(i==26)an++;
    for(i=m;i<n;i++){
        d[s[i]-'a']++;
        d[s[i-m]-'a']--;
        for(j=0;j<26;j++)
            if(d[j]>r[j])break;
        if(j==26)an++;
    }
    cout<<an<<endl;
    return 0;
}