#include <cstdio>

int p[110], s[110];
int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
int main(){
    int n, m, ans = 0; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) p[i] = i, s[i] = 1;
    for(int i = 0; i < m; ++i){
        int a, b; scanf("%d%d", &a, &b);
        int ta = find(a), tb = find(b);
        if(ta==tb && (s[ta]&1)) ans++;
        p[tb] = p[ta]; s[ta] += s[tb];
    }
    if((n-ans)&1) ans++;
    printf("%d\n", ans);
    return 0;
}