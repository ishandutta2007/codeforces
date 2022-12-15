#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
char s[55][55],ans[55][55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=(i+j)%2?'W':'R';
        int f=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if((s[i][j]=='W'||s[i][j]=='R')&&s[i][j]!=ans[i][j])
                    f=0;
        if(f){
            puts("YES");
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=m;j++)
                    printf("%c",ans[i][j]);
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=(i+j)%2?'R':'W';
        f=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if((s[i][j]=='W'||s[i][j]=='R')&&s[i][j]!=ans[i][j])
                    f=0;
        if(f){
            puts("YES");
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=m;j++)
                    printf("%c",ans[i][j]);
            continue;
        }
        puts("NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp