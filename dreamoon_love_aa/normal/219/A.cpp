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
char s[11111];
int k,d[26];
string str;
int main(){
    int i,j,k,n;
    cin>>k;
    scanf("%s",s);
    for(i=0;s[i];i++)d[s[i]-'a']++;
    for(i=0;i<26;i++)
        if(d[i]%k)break;
    if(i<26){
        puts("-1");
        return 0;
    }
    for(i=0;i<26;i++){
        for(j=0;j<d[i]/k;j++)str+=i+'a';
    }
    for(i=0;i<k;i++)cout<<str;
    cout<<endl;
    return 0;
}