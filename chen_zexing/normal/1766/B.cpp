#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        map <string,int> mp;
        int n,f=0;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=2;i<=n;i++){
            string t;
            t+=s[i-1],t+=s[i];
            if(mp[t]) f=1;
            if(i>2){
                t="";
                t+=s[i-2],t+=s[i-1];
                mp[t]=1;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}