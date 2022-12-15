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
char s[55][55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int f=0;
        int fl=1;
        for(int i=2;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=m;j++) if(s[i][j]!=s[1][j]) cnt++;
            if(cnt>1) fl=0;
        }
        if(fl){
            for(int i=1;i<=m;i++) printf("%c",s[1][i]);
            puts("");
            continue;
        }
        char o[15];
        for(int i=1;i<=m;i++) o[i]=s[1][i];
        for(int i=1;i<=m&&!f;i++){
            for(int j=0;j<26&&!f;j++){
                s[1][i]='a'+j;
                fl=1;
                for(int k=2;k<=n;k++){
                    int cnt=0;
                    for(int t=1;t<=m;t++) if(s[k][t]!=s[1][t]) cnt++;
                    if(cnt>1) fl=0;
                }
                if(fl){
                    for(int k=1;k<=m;k++) printf("%c",s[1][k]);
                    puts("");
                    f=1;
                    continue;
                }
            }
            s[1][i]=o[i];
        }
        if(!f) puts("-1");
    }
    return 0;
}