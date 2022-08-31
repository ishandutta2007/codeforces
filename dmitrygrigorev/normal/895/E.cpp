#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
struct Vertex{D summ; D p1; D p2; bool p;};
vector<Vertex> rmq;
vector<int> data;
void create(int i, int l, int r){
    if (r - l == 1){
        rmq[i].summ = data[l];
    }
    else{
        int mid =(l+r) / 2;
        create(2*i+1, l, mid);
        create(2*i+2, mid, r);
        rmq[i].summ = rmq[2*i+1].summ + rmq[2*i+2].summ;
    }
}
void push(int i, int l, int r){
    if (!rmq[i].p) return;
    rmq[i].p = false;
    rmq[2*i+1].p = true;
    rmq[2*i+2].p = true;
    int mid = (l + r) / 2;
    D L1 = (mid - l);
    D L2 = r - mid;
    rmq[2*i+1].summ = (rmq[i].p1 * rmq[2*i+1].summ) + rmq[i].p2*L1;
    rmq[2*i+2].summ = (rmq[i].p1 * rmq[2*i+2].summ) + rmq[i].p2*L2;
    rmq[2*i+1].p1 *= rmq[i].p1;
    rmq[2*i+2].p1 *= rmq[i].p1;
    rmq[2*i+1].p2 = rmq[2*i+1].p2 * rmq[i].p1 + rmq[i].p2;
    rmq[2*i+2].p2 = rmq[2*i+2].p2 * rmq[i].p1 + rmq[i].p2;
    rmq[i].p1 = 1;
    rmq[i].p2 = 0;
}
D get(int i, int l, int r, int l1, int r1){
    if (r - l > 1) push(i, l, r);
    if (l1 >= r1) return 0;
    if (l1 == l && r1 == r) return rmq[i].summ;
    int mid = (l+r) / 2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
}
void prot(int i, int l, int r, int l1, int r1, D a, D b){
    if (r - l > 1) push(i, l, r);
    if (l1 >= r1) return;
    if (l1 == l && r1 == r){
        rmq[i].summ = rmq[i].summ * a + b * (D) (r - l);
        rmq[i].p = true;
        rmq[i].p1 = a;
        rmq[i].p2 = b;
        return;
    }
    int mid = (l+r) / 2;
    prot(2*i+1, l, mid, l1, min(r1, mid), a, b);
    prot(2*i+2, mid, r, max(l1, mid), r1, a, b);
    rmq[i].summ = rmq[2*i+1].summ + rmq[2*i+2].summ;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ai, q;
    cin >> n >> q;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    for (int i=0; i < 4*n; i++){
        Vertex v = {0, 1, 0, false};
        rmq.push_back(v);
    }
    create(0, 0, n);
    cout.precision(20);
    for (int i=0; i < q; i++){
        int type, lf, rf, ls, rs;
        cin >> type;
        if (type == 1){
            cin >> lf >> rf >> ls >> rs;
            D s1 = get(0, 0, n, lf-1, rf) / (D) (rf - lf + 1);
            D s2 = get(0, 0, n, ls-1, rs) / (D) (rs - ls + 1);
            D ot1 = (D) 1 / (D) (rf - lf + 1);
            D ot2 = (D) 1 / (D) (rs - ls + 1);
            D ost1 = (D) 1 - ot1;
            D ost2 = (D) 1 - ot2;
            prot(0, 0, n, lf-1, rf, ost1, ot1*s2);
            prot(0, 0, n, ls-1, rs, ost2, ot2*s1);
        }
        else{
            cin >> lf >> rf;
            cout << get(0, 0, n, lf-1, rf) << "\n";
        }
    }
    return 0;
}