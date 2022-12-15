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
char s[400005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%s",s+1);
        int n=a+b,f=1;
        for(int i=1;i<=n;i++) {
            if(s[i]=='?') {
                if (s[i] == '?' && s[n - i + 1] != '?') {
                    if (s[n - i + 1] == '0') a--, s[i] = '0';
                    else b--, s[i] = '1';
                }
            }
            else if(s[i]=='0') a--;
            else b--;
            if(s[i]!='?'&&s[n-i+1]!='?'&&s[i]!=s[n-i+1]) f=0;
        }
        for(int i=1;i<=n/2;i++){
            if(s[i]=='?'){
                if(a>=2) s[i]=s[n-i+1]='0',a-=2;
                else if(b>=2) s[i]=s[n-i+1]='1',b-=2;
            }
        }
        if(n%2&&s[n/2+1]=='?'){
            if(a>0) s[n/2+1]='0',a--;
            else if(b>0) s[n/2+1]='1',b--;
        }
        if(a!=0||b!=0||!f){
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++) printf("%c",s[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp