#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
char s[105][105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n/2;i++)
            for(int j=1;j<=n/2;j++){
                int cnt=0;
                cnt+=s[i][j]-'0',cnt+=s[j][n-i+1]-'0';
                cnt+=s[n-j+1][i]-'0',cnt+=s[n-i+1][n-j+1]-'0';
                ans+=min(cnt,4-cnt);
            }
        if(n%2){
            for(int i=1;i<=n/2;i++){
                int cnt=0;
                cnt+=s[n/2+1][i]-'0',cnt+=s[n/2+1][n-i+1]-'0';
                cnt+=s[i][n/2+1]-'0',cnt+=s[n-i+1][n/2+1]-'0';
                ans+=min(cnt,4-cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//unordered_map
//cf