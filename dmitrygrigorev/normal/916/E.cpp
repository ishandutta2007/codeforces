#include <bits/stdc++.h>
#define int long long
using namespace std;
const int LG = 19;
int binup[100000][LG];
vector<int> val;
vector<vector<int> > data;
vector<int> H, tin, tout, d;
int timer;
vector<int> rmq, pushs;
vector<int> euler;
int dfs(int vertex, int last, int lvl){
    int X = 1;
    d[vertex] = lvl;
    if (last != -1){
        binup[vertex][0] = last;
        int v = last;
        int C = 0;
        while (binup[v][C] != -1){
            binup[vertex][C+1] = binup[v][C];
            v = binup[v][C];
            C++;
        }
    }
    tin[vertex] = timer;
    timer++;
    euler.push_back(vertex);
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        X += dfs(to, vertex, lvl+1);
    }
    H[vertex] = X;
    tout[vertex] = timer;
    timer++;
    euler.push_back(vertex);
    return X;
}
void push(int i, int l, int r){
    if (r - l <= 1) return;
    if (pushs[i] == 0) return;
    int P = pushs[i];
    int mid = (l+r) / 2;
    pushs[2*i+1] += P;
    rmq[2*i+1] += P*(mid-l);
    rmq[2*i+2] += P*(r-mid);
    pushs[2*i+2] += P;
    pushs[i] = 0;
}
void create(int i, int l, int r){
    if (r - l == 1){
        rmq[i] = val[euler[l]];
        return;
    }
    int mid = (l+r) / 2;
    create(2*i+1, l, mid);
    create(2*i+2, mid, r);
    rmq[i] = rmq[2*i+1] + rmq[2*i+2];
}
void change(int i, int l, int r, int l1, int r1, int V){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        rmq[i] += V * (r-l);
        pushs[i] += V;
        return;
    }
    int mid = (l+r) / 2;
    change(2*i+1, l, mid, l1, min(r1, mid), V);
    change(2*i+2, mid, r, max(l1, mid), r1, V);
    rmq[i] = rmq[2*i+1] + rmq[2*i+2];
}
int get(int i, int l, int r, int l1, int r1){
    push(i, l, r);
    if (l1 >= r1) return 0;
    if (l == l1 && r == r1){
        return rmq[i];
    }
    int mid = (l+r) / 2;
    int ret = 0;
    ret += get(2*i+1, l, mid, l1, min(r1, mid));
    ret += get(2*i+2, mid, r, max(l1, mid), r1);
    return ret;
}
int lca(int a, int b){
    if (a == b) return a;
    if (tin[a] < tin[b] && tout[a] > tout[b]) return a;
    if (tin[b] < tin[a] && tout[b] > tout[a]) return b;
    for (int i=LG-1; i >= 0; i--){
        int C = binup[a][i];
        if (C == -1) continue;
        if (tin[C] < tin[b] && tout[C] > tout[b]) continue;
        a = C;
    }
    return binup[a][0];
}
int pred(int a, int b){
    if (a == b) return true;
    if (tin[a] < tin[b] && tout[a] > tout[b]) return true;
    return false;
}
int podd(int a, int b){
    int L = tin[a];
    int R = tout[a] + 1;
    change(0, 0, timer, L, R, b);
}
int gpod(int a){
    int L = tin[a];
    int R = tout[a] + 1;
    return get(0, 0, timer, L, R) / 2;
}
int kpr(int a, int b){
    for (int i=LG-1; i >= 0; i--){
        int ba = (1LL << i) & b;
        if (ba != 0){
            a = binup[a][i];
        }
    }
    return a;
}
signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i=0; i < n; i++){
        for (int j=0; j < LG; j++) binup[i][j] = -1;
    }
    for (int i=0; i < n; i++){
        int A;
        cin >> A;
        val.push_back(A);
        vector<int> help;
        data.push_back(help);
        tin.push_back(-1);
        tout.push_back(-1);
        H.push_back(-1);
        d.push_back(-1);
    }
    for (int i=0; i < n-1; i++){
        int A, B;
        cin >> A >> B;
        data[A-1].push_back(B-1);
        data[B-1].push_back(A-1);
    }
    timer = 0;
    dfs(0, -1, 0);
    for (int i=0; i < 4*timer; i++){
        rmq.push_back(0);
        pushs.push_back(0);
    }
    create(0, 0, timer);
    int D = 0;
    int root = 0;
    for (int i=0; i < q; i++){
        //cout << i << endl;
        int T;
        cin >> T;
        if (T == 1){
            int N;
            cin >> N;
            root = N-1;
        }
        if (T == 2){
            int U, V, W;
            cin >> U >> V >> W;
            U--;
            V--;
            if (pred(root, U) && pred(root, V)){
                if (lca(U, V) == root){
                    D += W;
                }
                else{
                    int L = lca(U, V);
                    podd(L, W);
                }
            }
            else{
                if (lca(root, U) == root || lca(root, V) == root){
                    D += W;
                }
                else{
                    int F = lca(U, root);
                    int S = lca(V, root);
                    int L = lca(U, V);
                    if (!pred(L, F) && !pred(L, S)){
                        podd(L, W);
                    }
                    else{
                        if (pred(F, S) && !pred(S, F)) swap(F, S);
                        int diff = abs(d[F] - d[root]);
                        int Nu = kpr(root, diff-1);
                        D += W;
                        podd(Nu, -W);
                    }
                }
            }
        }
        if (T == 3){
            int U;
            cin >> U;
            U--;
            if (U == root){
                cout << gpod(0) + D*n << endl;
            }
            else{
                if (pred(U, root)){
                    int diff = abs(d[U] - d[root]);
                    int Nu = kpr(root, diff-1);
                   // cout << gpod(Nu) << endl;
                    cout << gpod(0) - gpod(Nu) + (n - H[Nu]) * D << endl;
                }
                else{
                    cout << gpod(U) + H[U] * D << endl;
                }
            }
        }
    }
    return 0;
}