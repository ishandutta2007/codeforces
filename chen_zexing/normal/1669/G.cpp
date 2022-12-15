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
#include <random>
using namespace std;
char s[55][55];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=m;i++)
            for(int j=n;j>=1;j--)
                if(s[j][i]=='*'){
                    int now=j;
                    while(now<n&&s[now+1][i]=='.') swap(s[now][i],s[now+1][i]),now++;
                }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%c",s[i][j]);
    }
    return 0;
}
//unordered_map