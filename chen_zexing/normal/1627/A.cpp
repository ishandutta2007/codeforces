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
using namespace std;
char s[55][55];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m,r,c,fl=0,f=0;
        cin>>n>>m>>r>>c;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='B')
                    f=1;
        if(s[r][c]=='B'){
            puts("0");
            continue;
        }
        for(int i=1;i<=n;i++) if(s[i][c]=='B') fl=1;
        for(int i=1;i<=m;i++) if(s[r][i]=='B') fl=1;
        if(!f) puts("-1");
        else if(fl) puts("1");
        else puts("2");
    }
    return 0;
}