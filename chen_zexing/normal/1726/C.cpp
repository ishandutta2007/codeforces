#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,ans=1;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<n*2;i++) if(s[i]=='('&&s[i+1]=='(') ans++;
        printf("%d\n",ans);
    }
    return 0;
}