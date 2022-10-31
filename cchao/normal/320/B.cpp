#include <cstdio>
#include <cstring>
int n;
int x[110], y[110], sz=0;
int q[110], vis[110], front, tail;
int f(int a, int b) {
    memset(vis, 0, sizeof vis);
    front = tail = 0;
    q[tail++] = a; vis[a] = 1;
    while(front < tail) {
        int t = q[front++];
        if(t == b) return 1;
        for(int i = 0; i < sz; ++i) {
            if((x[i] < x[t] && x[t] < y[i]) ||
               (x[i] < y[t] && y[t] < y[i]))
            {
                if(vis[i] == 0) { q[tail++] = i; vis[i] = 1; }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    int type, op1, op2;
    while(n--) {
        scanf("%d%d%d", &type, &op1, &op2);
        if(type == 1) { x[sz]=op1; y[sz] = op2; sz++; }
        else puts(f(op1-1, op2-1) ? "YES" : "NO");
    }
    return 0;
}