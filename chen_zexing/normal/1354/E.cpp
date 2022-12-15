#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
#define dbg(x...) do { cout << "\033[32;1m" << #x <<" -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<class T, class... Ts> void err(const T& arg,const Ts&... args) { cout << arg << " "; err(args...); }
const int N = 5000 + 5;
const int M = 200010;
int head[N], ver[M], nxt[M], tot, cnt;
int n, m, n1, n2, n3;
int c[N], be[N], c1[N], c2[N], rev[N];
int d[N][N];
void add(int x, int y){
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
bool dfs(int x, int col){
    c[x] = col;
    be[x] = cnt;
    if(c[x] == 1) c1[cnt] ++;
    else c2[cnt] ++;
    for(int i=head[x];i;i=nxt[i]){
        int y = ver[i];
        if(!c[y]){
            if(!dfs(y, 3 - col)) return false;
        }
        if(c[y] + c[x] != 3) return false;
    }
    return true;
}
int main(){
    scanf("%d%d", &n,&m);
    scanf("%d%d%d", &n1, &n2, &n3);
    for(int i=1;i<=m;i++){
        int x, y;scanf("%d%d", &x, &y);
        add(x, y);add(y, x);
    }
    d[0][0] = 1;
    for(int i=1;i<=n;i++){
        if(c[i]) continue;
        cnt++;
        if(!dfs(i, 1)){
            puts("NO");
            return 0;
        }
        for(int j=c1[cnt];j<=n2;j++){
            d[cnt][j] |= d[cnt-1][j-c1[cnt]];
        }
        for(int j=c2[cnt];j<=n2;j++){
            d[cnt][j] |= d[cnt-1][j-c2[cnt]];
        }
    }
    if(!d[cnt][n2]) {
        puts("NO");return 0;
    }
    puts("YES");
    while(cnt){
        rev[cnt] = d[cnt-1][n2-c1[cnt]];
        if(rev[cnt]) n2 -= c1[cnt];
        else n2 -= c2[cnt];
        cnt --;
    }
    for(int i=1;i<=n;i++){
        if(rev[be[i]]) c[i] = 3 - c[i];
        if(c[i] == 2) putchar('2');
        else if(n1 > 0) putchar('1'), n1--;
        else putchar('3'); 
    }

    return 0;
}