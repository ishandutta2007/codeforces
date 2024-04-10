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
int d[26];
int main(){
    int i,j,k,n;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++){
        d[s[i]-'a']++;
    }
    k=0;
    for(i=0;i<26;i++)
        if(d[i]&1)k++;
    if(k<=1||(k&1))puts("First");
    else puts("Second");
    return 0;
}