#include <bits/stdc++.h>

using namespace std;
struct Vertex{int d; long long sx; long long sy; int tx;};
struct Man{int x; int y; int d; int ind;};
vector<Vertex> rmq;
vector<Man> men;
bool cmp(Man &a, Man &b){
    return (a.d < b.d);
}
void change(int i){
    rmq[i].sx = rmq[2*i+1].sx + rmq[2*i+2].sx;
    rmq[i].sy = rmq[2*i+1].sy + rmq[2*i+2].sy;
    rmq[i].tx = rmq[2*i+1].tx + rmq[2*i+2].tx;
}
void construct(int i, int l, int r){
    if (r-l==1){
        rmq[i].d = men[l].d;
        rmq[i].sx = men[l].x;
        rmq[i].sy = men[l].y;
        rmq[i].tx = 1;
        return;
    }
    int mid = (l+r)/2;
    construct(2*i+1, l, mid);
    construct(2*i+2, mid, r);
    change(i);
}
void Close(int i, int l, int r, int kek){
    if (r-l==1){
        rmq[i].sx = 0;
        rmq[i].sy = 0;
        rmq[i].tx = 0;
        return;
    }
    int mid = (l+r)/2;
    if (kek < mid) Close(2*i+1, l, mid, kek);
    else Close(2*i+2, mid, r, kek);
    change(i);
}
void Open(int i, int l, int r, int kek){
    if (r-l==1){
        rmq[i].sx = men[l].x;
        rmq[i].sy = men[l].y;
        rmq[i].tx = 1;
        return;
    }
    int mid = (l+r)/2;
    if (kek < mid) Open(2*i+1, l, mid, kek);
    else Open(2*i+2, mid, r, kek);
    change(i);
}
Vertex cc(Vertex &a, Vertex &b){
    a.sx += b.sx;
    a.sy += b.sy;
    a.tx += b.tx;
}
void ask(int i, int l, int r, int l1, int r1, Vertex &vt){
    if (l1 >= r1) return;
    if (l==l1 && r==r1){
        cc(vt, rmq[i]);
        return;
    }
    int mid = (l+r)/2;
    ask(2*i+1, l, mid, l1, min(r1, mid), vt);
    ask(2*i+2, mid, r, max(l1, mid), r1, vt);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        men.push_back({x, y, x-y, i});
    }
    sort(men.begin(), men.end(), cmp);
    for (int i=0;i<4*n;i++) rmq.push_back({});
    construct(0, 0, n);
    vector<int> where(n);
    for (int i=0;i<n;i++) where[men[i].ind] = i;
    vector<vector<int> > bad(n);
    for (int i=0;i<n;i++) bad[i].push_back(i);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        bad[a].push_back(b);
        bad[b].push_back(a);
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < bad[i].size(); j++){
            int ind = where[bad[i][j]];
            Close(0, 0, n, ind);
        }
        int ind = where[i];
        int D = men[ind].x - men[ind].y;
        int L = -1, R = n;
        while (R-L>1){
            int M = (L+R)/2;
            if (men[M].d < D) L = M;
            else R = M;
        }
        Vertex af = {0, 0, 0, 0}, bf = {0, 0, 0, 0};
        ask(0, 0, n, 0, L+1, af), ask(0, 0, n, R, n, bf);
        cout << af.tx * (long long)men[ind].y + af.sx + bf.sy + bf.tx * (long long)men[ind].x << " ";
        for (int j=0; j < bad[i].size(); j++){
            int ind = where[bad[i][j]];
            Open(0, 0, n, ind);
        }
    }


}