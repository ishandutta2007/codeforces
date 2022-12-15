#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        int cnt=1;
        for(int i=2;i<=n;i++) if(s[i]!=s[i-1]) cnt++;
        if(s[1]=='0') printf("%d\n",max(0,cnt-2));
        else printf("%d\n",max(0,cnt-1));
    }
    return 0;
}