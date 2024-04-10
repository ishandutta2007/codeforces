#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        int fl=1;
        for(int i=n,cnt=0;i;i--){
            if(s[i]=='A') cnt++;
            else cnt--;
            if(cnt<0) fl=0;
        }
        puts(fl?"Yes":"No");
    }
    return 0;
}