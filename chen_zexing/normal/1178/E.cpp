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
char s[1000005];
vector <char> v;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        for(int i=l;i>=1;i--) s[i]=s[i-1];
        for(int i=1;i<=l/4;i++){
            int cnt[3]={};
            cnt[s[i*2-1]-'a']++;
            cnt[s[i*2]-'a']++;
            cnt[s[l-i*2+2]-'a']++;
            cnt[s[l-i*2+1]-'a']++;
            for(int j=0;j<3;j++)
                if(cnt[j]>1)
                {
                    v.push_back(char('a'+j));
                    break;
                }
        }
        for(int i=0;i<v.size();i++) printf("%c",v[i]);
        if(l%4) printf("%c",s[l/2+1]);
        for(int i=v.size()-1;i>=0;i--) printf("%c",v[i]);
    }
    return 0;
}