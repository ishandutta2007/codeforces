#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006

int n;
char s[MAXN];
int dp[MAXN][2];
int nxt[MAXN];
int fa[MAXN];
int mxlen[MAXN];

int find(int v){
    return (fa[v] == v)?v:fa[v] = find(fa[v]);
}

int main(){
    scanf("%d%s", &n, s); s[n] = '$';
    stack<pair<int, int>> st; st.push({MAXN, n});
    for(int i = n-1; i>=0; --i){
        dp[i][0] = (s[i] == '0' || s[i] == '?')?dp[i+1][0]+1:0;
        dp[i][1] = (s[i] == '1' || s[i] == '?')?dp[i+1][1]+1:0;
        int tmp = max(dp[i][0], dp[i][1]);
        while(st.top().first <= tmp) st.pop();
        nxt[i] = st.top().second; st.push({tmp, i});
        mxlen[i] = tmp;
    }
    for(int i = 0; i<=n; i++) fa[i] = i;
    for(int j = 1; j<=n; j++){
        int ans = 0;
        int ind = 0;
        while(ind < n){
            int f = find(ind);
            if(f == n) break;
            if(mxlen[f] >= j){
                ans++;
                ind = f+j;
            }
            else{
                while(f != n && mxlen[f] < j) fa[f] = nxt[f], f = find(f);
                if(f == n) break;
                ans++;
                ind = f+j;
            }
        }
        printf("%d\n", ans);
    }
}