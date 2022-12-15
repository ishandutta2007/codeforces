#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%s",s+1);
        n=strlen(s+1);
        int fl=1,pre=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='A') pre++;
            else pre--;
            if(pre<0) fl=0;
        }
        if(s[1]=='B'||s[n]!='B') fl=0;
        puts(fl?"YES":"NO");
    }
    return 0;
}