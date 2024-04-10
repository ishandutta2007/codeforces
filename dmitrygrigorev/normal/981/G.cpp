#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Vertex{int l; int r; int pr; int sz; int lg; int rg;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
vector<int> roots;
int MOD = 998244353;
vector<int> rmq;
vector<pair<int, int> > pushs;
vector<pair<int, int> > sas;
int n, q;
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
    }
    decart[vertex].sz = sz;
}
pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    int l = 1;
    if (decart[father].l != -1){
        l += decart[decart[father].l].sz;
    }
    if (l <= number){
        pair<int, int> p = split(decart[father].r, number - l);
        decart[father].r = p.first;
        p.first = father;
        update(father);
        return p;
    }
    pair<int, int> p = split(decart[father].l, number);
    decart[father].l = p.second;
    p.second = father;
    update(father);
    return p;
}
int merg(int first, int second){
    if (first == -1) return second;
    if (second == -1) return first;
    if (decart[first].pr >= decart[second].pr){
        int v = merg(decart[first].r, second);
        decart[first].r = v;
        update(first);
        return first;
    }
    int v = merg(first, decart[second].l);
    decart[second].l = v;
    update(second);
    return second;
}
void Change(int V, pair<int, int> &p, int df){
    rmq[V] *= p.first;
    rmq[V] %= MOD;
    rmq[V] += p.second*df;
    rmq[V] %= MOD;
    pushs[V].first *= p.first;
    pushs[V].second *= p.first;
    pushs[V].first %= MOD;
    pushs[V].second %= MOD;
    pushs[V].second += p.second;
    pushs[V].second %= MOD;
}
void push(int i, int l, int r){
    if (r - l <= 1) return;
    int mid = (l+r)/2;
    pair<int, int> p = pushs[i];
    Change(2*i+1, p, mid-l);
    Change(2*i+2, p, r-mid);
    pushs[i] = make_pair(1, 0);
}
void upd(int i, int l, int r, int l1, int r1, int tp){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l==l1 && r==r1){
        if (tp==1){
            rmq[i] += r-l;
            rmq[i] %= MOD;
            pushs[i] = make_pair(1, 1);
        }
        else{
            rmq[i] *= 2;
            rmq[i] %= MOD;
            pushs[i] = make_pair(2, 0);
        }
        return;
    }
    int mid = (l+r) / 2;
    upd(2*i+1, l, mid, l1, min(r1, mid), tp);
    upd(2*i+2, mid, r, max(l1, mid), r1, tp);
    rmq[i] = (rmq[2*i+1] + rmq[2*i+2]) % MOD;
}
int get_left(int base, int l){
    if (base == -1) return 0;
    int L = decart[base].l, R = decart[base].r;
    int sz = 1, lsz = 0, rsz = 0;
    if (L != -1) lsz += decart[L].sz;
    if (R != -1) rsz += decart[R].sz;
    if (decart[base].rg < l){
        return sz + lsz + get_left(R, l);
    }
    return get_left(L, l);
}
int get_right(int base, int l){
    if (base == -1) return 0;
    int L = decart[base].l, R = decart[base].r;
    int sz = 1, lsz = 0, rsz = 0;
    if (L != -1) lsz += decart[L].sz;
    if (R != -1) rsz += decart[R].sz;
    if (decart[base].lg > l){
        return get_right(L, l);
    }
    return sz + lsz + get_right(R, l);
}
void dwn(int base){
    if (base == -1) return;
    dwn(decart[base].l);
    sas.push_back(make_pair(decart[base].lg, decart[base].rg));
    dwn(decart[base].r);
}
void cch(int base, int tp, int g){
    if (tp == 0){
        if (decart[base].l != -1) cch(decart[base].l, tp, g);
        else{
            decart[base].lg = g;
            return;
        }
    }
    else{
        if (decart[base].r != -1) cch(decart[base].r, tp, g);
        else{
            decart[base].rg = g;
            return;
        }
    }
}
int gright(int vertex){
    if (vertex == -1) return -100;
    if (decart[vertex].r == -1) return decart[vertex].rg;
    return gright(decart[vertex].r);
}
int gleft(int vertex){
    if (vertex == -1) return -100;
    if (decart[vertex].l == -1) return decart[vertex].lg;
    return gleft(decart[vertex].l);
}
int get(int i, int l, int r, int l1, int r1){
    push(i, l, r);
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1) return rmq[i]%MOD;
    int mid = (l+r)/2;
    return (get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1)) % MOD;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=0; i < 4*n; i++){
        rmq.push_back(0);
        pushs.push_back(make_pair(1, 0));
    }
    for (int i=0; i < n; i++){
        roots.push_back(-1);
    }
    for (int i=0; i < q; i++){
        int t;
        cin >> t;
        if (t==1){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--, x--;
            int a = get_left(roots[x], l);
            int b = get_right(roots[x], r);
            pair<int, int> p = split(roots[x], a);
            pair<int, int> p1 = split(p.second, b-a);
            sas.clear();
            dwn(p1.first);
            if (sas.size() != 0){
                if (sas[0].first < l){
                    Vertex nv = {-1, -1, rand(), 1, sas[0].first, l-1};
                    decart.push_back(nv);
                    p.first = merg(p.first, decart.size() - 1);
                    cch(p1.first, 0, l);
                    sas[0].first = l;
                }
                if (sas.back().second > r){
                    Vertex nv = {-1, -1, rand(), 1, r+1, sas.back().second};
                    decart.push_back(nv);
                    p1.second = merg(decart.size() - 1, p1.second);
                    cch(p1.first, 1, r);
                    sas.back().second = r;
                }
            }
            for (int j=0; j < sas.size(); j++){
                upd(0, 0, n, sas[j].first, sas[j].second + 1, 2);
                //cout << sas[j].first << " " << sas[j].second << "*" << endl;
            }
            for (int j=1; j < sas.size(); j++){
                upd(0, 0, n, sas[j-1].second + 1, sas[j].first, 1);
               // cout << sas[j-1].second+1 << " " << sas[j].first - 1 << "+" << endl;
            }
            if (sas.size() == 0) upd(0, 0, n, l, r+1, 1);
            else{
                upd(0, 0, n, l, sas[0].first, 1);
                upd(0, 0, n, sas.back().second + 1, r + 1, 1);
            }
            Vertex nnv = {-1, -1, rand(), 1, l, r};
            decart.push_back(nnv);
            p1.first = decart.size() - 1;
            int gl = gright(p.first);
            if (gl == l-1){
                pair<int, int> p2 = split(p.first, decart[p.first].sz - 1);
                p.first = p2.first;
                cch(p1.first, 0, decart[p2.second].lg);
            }
            gl = gleft(p1.second);
            if (gl == r+1){
                pair<int, int> p3 = split(p1.second, 1);
                p1.second = p3.second;
                cch(p1.first, 1, decart[p3.first].rg);
            }
           // cout << decart[p1.first].lg << "!!" << decart[p1.first].rg << endl;
            roots[x] = merg(p.first, p1.first);
            roots[x] = merg(roots[x], p1.second);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(0, 0, n, l, r+1) << endl;
        }
    }
}