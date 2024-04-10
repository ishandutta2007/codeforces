#include <bits/stdc++.h>
#define int long long

using namespace std;
struct Snm{int r; int f;};
vector<Snm> snm;
int get(int v){
    if (snm[v].f == v) return v;
    snm[v].f = get(snm[v].f);
    return snm[v].f;
}
void un(int a, int b){
    if (snm[a].r < snm[b].r) swap(a, b);
    snm[b].f = a;
    if (snm[a].r == snm[b].r) snm[a].r++;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) snm.push_back({-1, -1});
    int cmp = 0;
    for (int i=0; i < n; i++){
        if (v[i] > l){
            snm[i] = {1, i};
            cmp++;
            if (i > 0 && snm[i-1].f != -1){
                un(get(i-1), get(i));
                cmp--;
            }
        }
    }
    for (int i=0;i<m;i++){
        int tp;
        cin >> tp;
        if (tp == 0) cout << cmp << endl;
        else{
        int p, d;
        cin >> p >> d;
        v[p-1] += d;
        if (v[p-1] > l){
            if (snm[p-1].r == -1){
                snm[p-1] = {1, p-1};
                cmp++;
                if (p-2>=0 && snm[p-2].f != -1){
                    un(get(p-2), get(p-1));
                    cmp--;
                }
                if (p < n && snm[p].f != -1){
                    un(get(p), get(p-1));
                    cmp--;
                }
            }
        }
        }
    }
}