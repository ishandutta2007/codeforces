/*input
abc
5
*/
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mid ((l + r) / 2)

const int maxn = 100005;
const double alpha = 0.7;

struct Node{
    int ls, rs, sid, size;
    double tag;
} node[maxn];

vector<int> rb_list;
int ptr = 0, root = 0;
double *tag[maxn];
string s;

void Subtree(int now) {
    if (node[now].ls) Subtree(node[now].ls);
    rb_list.emplace_back(now);
    if (node[now].rs) Subtree(node[now].rs);
}

void Maintain(int now) {
    node[now].size = node[node[now].ls].size + 1 + node[node[now].rs].size;   
}

int Rebuild(int lidx, int ridx, double l, double r) {
    int idx = (lidx + ridx) / 2, now = rb_list[idx];
    node[now].tag = (l + r) / 2;
    if (lidx <= idx - 1) node[now].ls = Rebuild(lidx, idx - 1, l, mid);
    else node[now].ls = 0;
    if (idx + 1 <= ridx) node[now].rs = Rebuild(idx + 1, ridx, mid, r);
    else node[now].rs = 0;
    Maintain(now);
    return now;
}

int CheckRebuild(int now, double l, double r) {
    if (node[node[now].ls].size > node[now].size * alpha || 
        node[node[now].rs].size > node[now].size * alpha) {
        Subtree(now);
        now = Rebuild(0, rb_list.size() - 1, l, r);
        return rb_list.clear(), now;
    }
    return now;
}

int Insert(int now, double l, double r, int sid) {
    if (now == 0) {
        Node &now = node[++ptr];
        now.sid = sid, now.tag = (l + r) / 2, now.size = 1;
        tag[sid] = &now.tag;
        return ptr;
    } else {
        now = CheckRebuild(now, l, r);
        if (mp(s[sid], *tag[sid + 1]) < mp(s[node[now].sid], *tag[node[now].sid + 1]))
             node[now].ls = Insert(node[now].ls, l, mid, sid);
        else node[now].rs = Insert(node[now].rs, mid, r, sid);
        return Maintain(now), now;
    }
}

int sa[maxn], rk[maxn];

void GetSuffixArray() {
    tag[s.size()] = &node[0].tag;
    for (int i = s.size(); i > 0; -- i)
        root = Insert(root, 0, 1, i - 1);
    Subtree(root);
    for (int i = 0; i < rb_list.size(); ++ i)
        rk[sa[i] = node[rb_list[i]].sid] = i;
    rb_list.clear();
}

int sp[maxn][20], lcp[maxn];

void GetLCP(){
    int n = s.size(), val = 0;
    for (int i = 0; i < n; ++ i) {
        if (rk[i] == 0) lcp[rk[i]] = 0;
        else {
            if (val) -- val;
            int p = sa[rk[i] - 1];
            while (val + i < n && val + p < n && s[val + i] == s[val + p])
                val ++;
            lcp[rk[i]] = val;
        }
    }
}
void getsp(){
    int n = s.size();
    for (int i = 0; i < n; ++ i) sp[rk[i]][0] = s.size() - i;
    for (int i = 1; i < n; ++ i) sp[i - 1][1] = lcp[i];
    for (int i = 2; i < 20; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if(j + (1 << (i - 2)) >= s.size()) continue;
            sp[j][i] = min(sp[j][i - 1], sp[j + (1 << (i - 2))][i - 1]);
        }
    }
}
int Query(int L, int R){
    int tmp = (L == R) ? 0 : 32 - __builtin_clz(R - L);
    return min(sp[L][tmp], sp[R - (1 << (tmp - 1))][tmp]);
}
int solve(int id, int len){
    int now = id;
    for (int i = 19; i >= 0; -- i) {
        int to = now + (1 << i);
        if(to < s.size() && Query(now, to) >= len) now = to;
    }
    return now;
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    int cnt = 0, k;
    cin >> s >> k;
    GetSuffixArray();
    GetLCP(); 
    getsp();

    for (int i = 0; i < s.size(); ++ i) {
        for (int ii = sa[i] + lcp[i]; ii < s.size(); ++ ii) {
            cnt += solve(i, ii - sa[i] + 1) - i + 1;
            if(cnt >= k) {
                for (int jj = sa[i]; jj < ii + 1; ++ jj) cout << s[jj];
                cout << endl;
                return 0;
            }
        }
    }
    cout << "No such line." << endl;
    // DBGG("cnt = ", cnt);
    return 0;
}