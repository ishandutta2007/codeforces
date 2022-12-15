#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        char s[15];
        scanf("%s",s+1);
        map <char,int> mp;
        for(int i=1;i<=n;i++) mp[s[i]]=1;
        if(mp['T']&&mp['i']&&mp['u']&&mp['m']&&mp['r']&&n==5) puts("YES");
        else puts("NO");
    }
    return 0;
}