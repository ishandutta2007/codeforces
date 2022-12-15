#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[500005];
int first[26];
int check(int x){
    for(int i=0;i<26&&i<s[x]-'a';i++)
        if(first[i]!=-1)
            return 1;
    return 0;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        memset(first,-1,sizeof(first));
        for(int i=0;i<l;i++){
            if(check(i)) puts("Ann");
            else puts("Mike");
            if(first[s[i]-'a']==-1) first[s[i]-'a']=i;
        }
    }
    return 0;
}