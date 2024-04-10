#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>  // tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

struct que {
    int num;
    int time;
    int quant;
    int tipo;
    int ind;
};

bool comp(que a, que b) {
    if (a.num != b.num) return a.num < b.num;
    if (a.time != b.time) return a.time < b.time;
    return a.quant < b.quant;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<que> V(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &V[i].tipo, &V[i].time, &V[i].num);
        V[i].quant = i;
        if (V[i].tipo == 3) V[i].ind = res++;
    }
    sort(V.begin(), V.end(), comp);
    ordered_set I;
    ordered_set T;
    vi R(res);
    int antnum = 0;
    for (int i = 0; i < n; ++i) {
        if (antnum != V[i].num) {
            antnum = V[i].num;
            T.clear();
            I.clear();
        }
        if (V[i].tipo == 1) I.insert(V[i].quant);
        else if (V[i].tipo == 2) T.insert(V[i].quant);
        else R[V[i].ind] = I.order_of_key(V[i].quant + 1) - T.order_of_key(V[i].quant + 1);
    }
    for (int i = 0; i < res; ++i) {
        printf("%d\n", R[i]);
    }
}