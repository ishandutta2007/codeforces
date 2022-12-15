#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[105],t[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,fl=1;
        cin>>n;
        scanf("%s",s+1),scanf("%s",t+1);
        for(int i=1;i<=n;i++){
            if(s[i]==t[i]||s[i]=='B'&&t[i]=='G'||s[i]=='G'&&t[i]=='B');
            else fl=0;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}