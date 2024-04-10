#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[2005][10];
int a[2005][10],f[2015][2015];
char d[10][7]={'1','1','1','0','1','1','1',
               '0','0','1','0','0','1','0',
               '1','0','1','1','1','0','1',
               '1','0','1','1','0','1','1',
               '0','1','1','1','0','1','0',
               '1','1','0','1','0','1','1',
               '1','1','0','1','1','1','1',
               '1','0','1','0','0','1','0',
               '1','1','1','1','1','1','1',
               '1','1','1','1','0','1','1'};
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%s", s[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int t = 0; t < 7; t++) {
                    if (s[i][t] == '0' && d[j][t] == '1') a[i][j]++;
                    else if (s[i][t] == '1' && d[j][t] == '0') {
                        a[i][j] = -1;
                        break;
                    }
                }
            }
        }
        memset(f,-1,sizeof(f));
        f[n+1][0]=0;
        for(int i=1;i<=k;i++) f[n+1][i]=-1;
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j <= k; j++)
                for (int t = 0; t <= 9; t++) {
                    if (a[i][t] == -1) continue;
                    if (f[i + 1][j] != -1)
                        f[i][j + a[i][t]] = t;
                }
        }
        if (f[1][k]==-1) {
            puts("-1");
            continue;
        }
        int now=k;
        for(int i=1;i<=n;i++){
            for(int j=9;j>=0;j--){
                if(a[i][j]!=-1&&now>=a[i][j]&&f[i+1][now-a[i][j]]!=-1){
                    printf("%d",j);
                    now-=a[i][j];
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}