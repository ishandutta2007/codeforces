#include <cstdio>
int n,s,t, p[100010], vis[100010]={0};
int solve(){
    int now = s, cnt = 0;
    while(now != t){
        now = p[now];
        cnt++;
        if(now==t) return cnt;
        if(vis[now]) return -1;
        else vis[now] = 1;
    }
    return cnt;
}
int main(){
    scanf("%d%d%d", &n, &s, &t);
    for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    printf("%d\n", solve());
    return 0;
}