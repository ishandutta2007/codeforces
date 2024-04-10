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
char s[1555];
bool good[26];
set<unsigned long long>H[1555];
int main(){
    int i,j,k,n,an=0;
    char tmp[32];
    gets(s);
    gets(tmp);
    for(i=0;i<26;i++)good[i]=tmp[i]-'0';
    scanf("%d",&k);
    n=strlen(s);
    for(i=0;i<n;i++){
        unsigned long long now=0;
        int bad=0;
        for(j=i;j<n;j++){
            now*=131;
            now+=s[j];
            if(!good[s[j]-'a'])bad++;
            if(bad>k)break;
            if(!H[j-i].count(now)){
                an++;
                H[j-i].insert(now);
            }
        }
    }
    printf("%d\n",an);
    return 0;
}