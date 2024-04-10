#include <cstdio>
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
using namespace std;
char s[2005][2005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0,c1=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                    c1+=s[i][j]=='1';
        for(int i=1;i<=n;i++){
            int cnt=0,x=1,y=i;
            for(int j=1;j<=n;j++){
                cnt+=s[x][y]-'0';
                x++,y++;
                if(y>n) y-=n;
            }
            ans=max(ans,cnt);
        }
        printf("%d\n",n-ans+c1-ans);
    }
    return 0;
}
//unordered_map