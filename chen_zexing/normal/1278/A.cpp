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
char s[105],ss[305];
int main() {
    int T;
    cin>>T;
    while(T--){
        int c[26]={};
        int l1,l2;
        scanf("%s",s);
        scanf("%s",ss);
        l1=strlen(s),l2=strlen(ss);
        for(int i=0;i<l1;i++) c[s[i]-'a']++;
        int ff=0;
        for(int i=0;i<l2-l1+1;i++)
        {
            int cnt[26]={};
            for(int j=i;j<i+l1;j++) cnt[ss[j]-'a']++;
            int f=1;
            for(int j=0;j<26;j++) if(cnt[j]!=c[j]) f=0;
            if(f) ff=1;
        }
        if(ff) puts("YES");
        else puts("NO");
    }
    return 0;
}