#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1000006;
queue <int> q;
set <int> s;
int b[maxn], p[maxn];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i){
        int x = read();
        if (x)
            s.insert(x);
    }
    for (int i = 1; i <= n; ++ i){
        b[i] = read();
        p[b[i]] = i;
    }
    if (p[1] == 0)
        p[1] = n + 1;
    bool flag = false;
    for (int i = p[1]; i <= n; ++ i)
        if (b[i] != i - p[1] + 1){
            flag = true;
            break;
        }
    if (! flag){
        for (int i = 1; i <= n; ++ i)
            q.push(b[i]);
        bool flag = false;
        for (int i = 1; i <= p[1] - 1; ++ i){
            int u = q.front(); q.pop();
            if (s.find(n - p[1] + 1 + i) == s.end()){
                flag = true;
                break;
            }
            s.insert(u);
        }
        if (! flag){
            cout << p[1] - 1 << endl;
            return 0;
        }
    }
    if (p[1] == n + 1)
        p[1] = 0;
    int mx = 0;
    for (int i = 1; i <= n; ++ i)
        mx = max(mx, p[i] - i + 1);
    cout << mx + n << endl;
}