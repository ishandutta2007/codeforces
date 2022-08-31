#include <bits/stdc++.h>
#define int long long

using namespace std;
#define TASKNAME ""
map<int, int> ms;
vector<int> cmp;
vector<vector<int> > sets;
vector<int> indixes;
vector<int> xr;
void create(int vertex){
    int sz = ms.size(), I = indixes.size();
    ms[vertex] = sz;
    xr.push_back(0);
    indixes.push_back(sets.size());
    cmp.push_back(I);
    sets.push_back({sz});
}
void Edge(int a, int b, int x){
    int A = ms[a], B = ms[b];
    //cout << A << " !! " << B << endl;
    int ea = cmp[A], eb = cmp[B];
    int ca = indixes[cmp[A]], cb = indixes[cmp[B]];
    //cout << sets[ca][0] << endl;
    //out << sets[cb][0] << endl;
    if (sets[ca].size() > sets[cb].size()){
        swap(cb, ca);
        swap(A, B);
        swap(ea, eb);
    }
    int Xr = x ^ xr[A] ^ xr[B];
    for (int i=0; i < sets[ca].size(); i++){
        int V = sets[ca][i];
        cmp[V] = eb;
        xr[V] ^= Xr;
        sets[cb].push_back(V);
    }
    //cout << cmp[A] << "::::" << cmp[B] << endl;
}
int ask(int l, int r){
    int A, B;
    if (ms.count(l)) A = ms[l];
    else{
        create(l);
        A = ms[l];
    }
    if (ms.count(r)) B = ms[r];
    else{
        create(r);
        B = ms[r];
    }
    //cout << "ASK " << A << " " << B << endl;
    if (cmp[A] != cmp[B])return -1;
    return xr[A] ^ xr[B];

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    int last = 0;
    for (int i=0; i < q; i++){
        int tp;
        cin >> tp;
        if (tp == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last, r ^= last, x^=last;
            if (l>r) swap(l, r);
            r++;
            int res = ask(l, r);
            if (res == -1){
                //cout << l << "!!!" << r << endl;
                Edge(l, r, x);
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            l ^= last, r ^= last;
            if (l > r) swap(l, r);
            r++;
            int et = ask(l, r);
            last = abs(et);
            cout << et << endl;
        }
    }


}