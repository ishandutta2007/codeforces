#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e3+100;
int n, m, k;
char g[N][N];
LL res = 0;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0;i<n;i++){
        scanf("%s", g[i]);
    }
    if (k==1){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (g[i][j]=='.')res++;
            }
        }
        cout<<res<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                cur++;
                if (cur >= k) res++;
            }
            else
                cur = 0;
        }
    }
    for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == '.') {
                cur++;
                if (cur >= k) res++;
            }
            else
                cur = 0;
        }
    }
    cout<<res<<endl;
    return 0;
}