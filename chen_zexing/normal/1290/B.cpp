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
char s[200005];
int cnt[200005][26];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        scanf("%s",s+1);
        int l=strlen(s+1),q;
        for(int i=1;i<=l;i++){
            for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
            cnt[i][s[i]-'a']++;
        }
        cin>>q;
        while(q--){
            int ll,rr;
            scanf("%d%d",&ll,&rr);
            if(ll==rr) puts("Yes");
            else if(s[ll]!=s[rr]) puts("Yes");
            else{
                int f=0;
                for(int j=0;j<26;j++) if(j!=s[ll]-'a'&&cnt[rr][j]-cnt[ll-1][j]) f++;
                puts(f>=2?"Yes":"No");
            }
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp