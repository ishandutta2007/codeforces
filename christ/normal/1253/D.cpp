#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MN = 2e5+1, INF = 2e9;
int p[MN], mx[MN], mn[MN],ret;
bool done[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return;
    p[fa] = fb;
    mx[fb] = max(mx[fb],mx[fa]);
    mn[fb] = min(mn[fa],mn[fb]);
    ++ret;
}
void check (int cur) {
    for (int i = mn[cur]; i <= mx[cur]; i++) {
        if (find(i) != cur) merge(i,cur);
    }
    done[cur] = 1;
}
int main() {
    int n,m,a,b;
    scanf ("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) p[i] = mx[i] = mn[i] = i;
    while (m--) {
        scanf ("%d %d",&a,&b);
        merge(a,b);
    }
    ret=0;
    for (int i = 1; i <= n; i++) if (!done[find(i)]) check(find(i));
    printf ("%d\n",ret);
	return 0;
}
//11649,6796