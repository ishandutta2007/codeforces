#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#define double long double
double eps = 1e-10;
#define int long long
using namespace std;
vector<vector<int> >  kekdata;
vector<int> tin, sz;
int cur=0;
void dfs(int vertex){
    tin[vertex] = cur++;
    sz[vertex] = 1;
    for (int i=0; i < kekdata[vertex].size(); i++){
        int to = kekdata[vertex][i];
        dfs(to);
        sz[vertex] += sz[to];
    }
}
vector<int> a, b;
struct Query{int l; int r; int tp; int delta;};
vector<Query> queries;
const int SQRT = 150;
int BLOCKS;
const int INF = 1e15;
struct Element{int b; int index; int value;};
bool cmp(Element &a, Element &b){
    return (a.b < b.b);
}
struct Line{int k; int b; int l; int r;};
int intersect(Line &a, Line &b){
    double C = a.b-b.b, Z = b.k - a.k;
    int R = ceil(C/Z+eps);
    return R;
}
struct CHT{
    vector<Line> arr, arr2;
    int ptr1, ptr2;
    CHT(){
        arr = {};
        arr2 = {};
        ptr1=0, ptr2=0;
    }
    void add_first_line(Line l){
        while (arr.size()){
            if (arr.back().k == l.k){
                if (arr.back().b >= l.b) return;
                else arr.pop_back();
                continue;
            }
            int pt = intersect(arr.back(), l);
            if (pt <= arr.back().l){
                arr.pop_back();
            }
            else{
                arr.back().r = pt;
                l.l = pt, l.r = INF;
                arr.push_back(l);
                break;
            }
        }
        if (!arr.size()){
            l.l=-INF, l.r = INF;
            arr.push_back(l);
        }
    }
    void add_second_line(Line l){
        while (arr2.size()){
            if (arr2.back().k == l.k){
                if (arr2.back().b <= l.b) return;
                else arr2.pop_back();
                continue;
            }
            int pt = intersect(arr2.back(), l);
            if (pt <= arr2.back().l){
                arr2.pop_back();
            }
            else{
                arr2.back().r = pt;
                l.l = pt, l.r = INF;
                arr2.push_back(l);
                break;
            }
        }
        //cout << endl;
        if (!arr2.size()){
            l.l=-INF, l.r = INF;
            arr2.push_back(l);
        }
    }
    int best(int x){
        int A = arr.size(), B = arr2.size();
        while (ptr1+1 < A && arr[ptr1+1].l <= x) ptr1++;
        while (ptr2+1 < B && arr2[ptr2+1].l <= x) ptr2++; 
        int tet1 = arr[ptr1].k * x + arr[ptr1].b;
        int tet2 = arr2[ptr2].k * x + arr2[ptr2].b;
        return max(abs(tet1), abs(tet2));
    }
};
void dfs2(int vertex, int S, int T){
    S += a[vertex];
    T += b[vertex];
    a[vertex] = S;
    b[vertex] = T;
    for (int i=0; i < kekdata[vertex].size(); i++){
        int to = kekdata[vertex][i];
        dfs2(to, S, T);
    }
}
vector<vector<Element> > arr;
vector<CHT> convex_huints;
vector<int> deltas;
void build_cht(int index){
    CHT here;
    for (int i=0; i < arr[index].size(); i++){
        int B = arr[index][i].b * arr[index][i].value;
        int K = arr[index][i].b;
        Line new_line = {K, B, -INF, INF};
        here.add_first_line(new_line);
    }
    for (int i=arr[index].size()-1; i >= 0; i--){
        int B = arr[index][i].b * arr[index][i].value;
        int K = arr[index][i].b;
        Line new_line = {K, B, -INF, INF};
        here.add_second_line(new_line);
    }
    convex_huints[index] = here;
}
int get_best(int index){
    return convex_huints[index].best(deltas[index]);
}
bool cmp2(int x, int y){
    return (tin[x] < tin[y]);
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    kekdata.resize(n, {});
    for (int i=0; i < n-1; i++){
        int x;
        cin >> x;
        kekdata[x-1].push_back(i+1);
    }
    tin.resize(n, -1), sz.resize(n, -1);
    dfs(0);
    a.resize(n, -1), b.resize(n, -1);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    dfs2(0, 0, 0);
    for (int i=0; i < q; i++){
        int tp;
        cin >> tp;
        if (tp==1){
            int v, x;
            cin >> v >> x;
            v--;
            int L = tin[v], R = tin[v]+sz[v]-1;
            queries.push_back({L, R, 1, x});
        }
        else{
            int v;
            cin >> v;
            v--;
            int L = tin[v], R = tin[v]+sz[v]-1;
            queries.push_back({L, R, 2, -1});
        }
    }
    BLOCKS = (n+SQRT-1)/SQRT;
    arr.resize(BLOCKS, {});
    convex_huints.resize(BLOCKS, {});
    deltas.resize(BLOCKS, 0);
    vector<int> order;
    for (int i=0;i<n;i++) order.push_back(i);
    sort(order.begin(), order.end(), cmp2);
    for (int i=0; i < BLOCKS; i++){
        int L = i*SQRT, R = min(n-1, (i+1)*SQRT - 1);
        for (int j=L; j <= R; j++){
            //cout << a[order[j]]*b[order[j]] << endl;
            arr[i].push_back({b[order[j]], j, a[order[j]]});
        }
        sort(arr[i].begin(), arr[i].end(), cmp);
    }
    for (int i=0; i < BLOCKS; i++){
        build_cht(i);
    }
    for (int i=0; i < queries.size(); i++){
        if (queries[i].tp == 1){
            int lq = queries[i].l, rq = queries[i].r;
            for (int j=0; j < BLOCKS; j++){
                int L = j*SQRT, R = min(n-1, (j+1)*SQRT - 1);
                if (lq <= L && rq >= R){
                    deltas[j] += queries[i].delta;
                    continue;
                }
                if (R < lq || L > rq) continue;
                L = max(L, lq);
                R = min(R, rq);
                for (int e=0; e < arr[j].size(); e++){
                    int I = arr[j][e].index;
                    if (I < L || I > R) continue;
                    //cout << I << " " << arr[j][e].value << endl;
                    arr[j][e].value += queries[i].delta;
                    //cout << I << " " << arr[j][e].value*arr[j][e].b << endl;
                }
                build_cht(j);
            }
        }
        else{
            int lq = queries[i].l, rq = queries[i].r;
            int ans = -1e18;
            //cout << "!!" << lq << " " << rq << endl;
            for (int j=0; j < BLOCKS; j++){
                int L = j*SQRT, R = min(n-1, (j+1)*SQRT - 1);
                if (lq <= L && rq >= R){
                    ans = max(ans, get_best(j));
                    continue;
                }
                if (R < lq || L > rq) continue;
                L = max(L, lq);
                R = min(R, rq);
                for (int e=0; e < arr[j].size(); e++){
                    int I = arr[j][e].index;
                    if (I < L || I > R) continue;
                    int T = arr[j][e].value + deltas[j];
                    int P = arr[j][e].b;
                    ans = max(ans, abs(T*P));
                }
            }
            cout << ans << "\n";
        }
    }
}