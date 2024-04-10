#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define ll long long

int n, Q, a[100100], l, r, L[100100], R[100100];
struct node{
    int v, w;
    node (int x, int y) { v = x; w = y; }
    bool operator < (const node a) const{
        return v < a.v;
    }
};

int main(){
    scanf("%d%d", &n, &Q);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);

    priority_queue<node> q;
    for(int i = 2; i <= n; i++) q.push(node(abs(a[i] - a[i - 1]), i - 1));
    set<int> qq;
    qq.insert(1); qq.insert(n);
    while(!q.empty()){
        node t = q.top(); q.pop();
        set<int>::iterator it1 = qq.upper_bound(t.w); it1--;
        set<int>::iterator it2 = qq.lower_bound(t.w + 1);
        L[t.w] = *it1;
        R[t.w] = *it2;
        qq.insert(t.w);
        qq.insert(t.w + 1);
    }

    while(Q--){
        scanf("%d%d", &l, &r);
        ll ans = 0;
        for(int i = l; i < r; i++)
            ans += (ll)(i - max(l, L[i]) + 1) * (min(r, R[i]) - i) * abs(a[i + 1] - a[i]);
        printf("%I64d\n", ans);
    }
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/