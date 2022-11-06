#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;
const int MAX = 10005;
int n, m;  
int u[MAX], v[MAX];
  
struct NODE {  
    int fa[505];
  
    void Init() {  
        for (int i = 0; i <= 505; i++) {  
            fa[i] = i;  
        }
    }  
  
    int Find(int x) {  
        return fa[x] == x ? x : fa[x] = Find(fa[x]);  
    }  
  
    void Union(int a, int b) {  
        int r1 = Find(a);  
        int r2 = Find(b);  
        if(r1 != r2)  
            fa[r1] = r2;  
    }  
}s[MAX], e[MAX];  
  
int solve(NODE left, NODE right, int n){    
    for (int i = 1; i <= n; i ++) { 
        right.Union(i, left.Find(i));
    }  
    int res = 0;  
    for (int i = 1; i <= n; i ++) {  
        if (right.Find(i) == i) {
            res ++;  
        }
    }
    return res;  
}  
  
int main() {  

    scanf("%d %d", &n, &m);  
    for (int i = 1; i <= m; i ++) {  
        scanf("%d %d", &u[i], &v[i]);
    }  
    s[0].Init();  
    e[m + 1].Init();  
    for (int i = 1; i <= m; i ++) {  
        s[i] = s[i - 1];  
        s[i].Union(u[i], v[i]);  
    }  
    for (int i = m; i >= 1; i --) {  
        e[i] = e[i + 1];  
        e[i].Union(u[i], v[i]);  
    }  
    int l, r, q;  
    scanf("%d", &q);  
    while(q --) {  
        scanf("%d %d", &l, &r);  
        printf("%d\n", solve(s[l - 1], e[r + 1], n));  
    }    
}