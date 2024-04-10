#include <bits/stdc++.h>
#define MAX 500005
#define INF (1e18)
#define eps (1e-10)
using namespace std;

int n, m, q;
int p[MAX], l[MAX], c[MAX];

double f(int x, int t){
    if(t == -1) return INF;
    if(t >= l[x]) return 0.0;
    return 1.0*p[x]*l[x]/(t+l[x]+1)/(t+l[x]);
}
double g(int x){
    return 1.0*p[x]*min(c[x], l[x])/(min(c[x], l[x])+l[x]);
}

struct node{
    int x, c;
    double w;
    node(int a = 0, int b = -1){
        x = a, c = b;
        w = f(x, c);
    }
    friend bool operator <(node a, node b){
        if(fabs(a.w-b.w) < eps) return a.x < b.x;
        return a.w < b.w;
    }
};

set<node> in, out;
set<node>::iterator it;
double ans = 0.0;

void add(){
    it = (--out.end());
    ans += it->w;
    int x = it->x;
    in.erase(node(x, c[x]-1)), in.insert(*it);
    out.erase(it), out.insert(node(x, ++c[x]));
}

void del(){
    it = in.begin();
    ans -= it->w;
    int x = it->x;
    out.erase(node(x, c[x]--)), out.insert(*it);
    in.erase(it), in.insert(node(x, c[x]-1));
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++){
        scanf("%d", &l[i]);
        out.insert(node(i, 0));
        in.insert(node(i, -1));
    }
    while(m--) add();
    int t, x;
    for(int i = 1; i <= q; i++){
        scanf("%d%d", &t, &x);
        out.erase(node(x, c[x]));
        in.erase(node(x, c[x]-1));
        ans -= g(x);
        if(t == 1) l[x]++;
        else l[x]--;
        out.insert(node(x, c[x]));
        in.insert(node(x, c[x]-1));
        ans += g(x);
        while(out.rbegin()->w > (in.begin()->w+eps)) del(), add();
        printf("%.7lf\n", ans);
    }
}