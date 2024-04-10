#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 555555;

struct Node {
    int l, r, emptyExist, flag;
}T[N * 4];

int n, fa[N];
vector<int> e[N];
int posL[N], posR[N], tot;
int stack[N], en[N];
void dfs(int root) {
    tot = 0;
    int top = 0;
    stack[++top] = root;
    en[top] = 0;
    posL[1] = ++tot;
    while(top) {
        int x = stack[top];
        if (en[top] == e[x].size()) {
            posR[x] = tot;
            top--;
            continue;
        }
        int y = e[x][en[top]];
        en[top]++;
        if (y == fa[x])
            continue;
        fa[y] = x;
        posL[y] = ++tot;
        stack[++top] = y;
        en[top] = 0;
        //printf("%d ", y);
    }
}

void build(int root, int l, int r) {
    T[root].l = l; 
    T[root].r = r;
    T[root].emptyExist = 1;
    T[root].flag = 0;
    if (l == r)
        return ;
    else {
        int mid = (l + r) >> 1;
        build(root * 2, l, mid);
        build(root * 2 + 1, mid + 1, r);
    }
}

void push(Node &a, Node &b, Node &c) {
    if (a.flag) {
        a.flag = 0;
        b.flag = c.flag = 1;
        b.emptyExist = c.emptyExist = 0;
    }
}

void update(Node &a, Node &b, Node &c) {
    a.emptyExist = (b.emptyExist | c.emptyExist);
}

int water(int root, int l, int r) {
    if (l <= T[root].l && T[root].r <= r) {
        int res = T[root].emptyExist;
        T[root].emptyExist = 0;
        T[root].flag = 1;
        return res;
    }
    push(T[root], T[root * 2], T[root * 2 + 1]);
    int mid = (T[root].l + T[root].r) / 2;
    int res = 0;
    if (l <= mid)
        res |= water(root * 2, l, r);
    if (r > mid)
        res |= water(root * 2 + 1, l, r);
    update(T[root], T[root * 2], T[root * 2 + 1]);
    return res;
}

void empty(int root, int pos) {
    if (T[root].l == T[root].r) {
        T[root].emptyExist = 1;
        T[root].flag = 0;
        return ;
    }
    push(T[root], T[root * 2], T[root * 2 + 1]);
    int mid = (T[root].l + T[root].r) / 2;
    if (pos <= mid)
        empty(root * 2, pos);
    else
        empty(root * 2 + 1, pos);
    update(T[root], T[root * 2], T[root * 2 + 1]);
}

int ask(int root, int l, int r) {
    if (l <= T[root].l && T[root].r <= r) {
        return T[root].emptyExist;
    }
    push(T[root], T[root * 2], T[root * 2 + 1]);
    int mid = (T[root].l + T[root].r) / 2, res = 0;
    if (l <= mid)
        res |= ask(root * 2, l, r);
    if (r > mid)
        res |= ask(root * 2 + 1, l, r);
    update(T[root], T[root * 2], T[root * 2 + 1]);
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    //for(int i = 1; i <= n; i++)
        //printf("%d %d\n", posL[i], posR[i]);
    while(q--) {
        int type, v;
        scanf("%d %d", &type, &v);
        if (type == 1) {
            int exist = water(1, posL[v], posR[v]);
            if (exist && fa[v])
                empty(1, posL[fa[v]]);
        } else if (type == 2) {
            empty(1, posL[v]);
        } else {
            if (ask(1, posL[v], posR[v]))
                printf("0\n");
            else
                printf("1\n");
        }
    }
    return 0;
}