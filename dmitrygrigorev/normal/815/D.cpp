#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
using namespace std;
int n, p, q, r, ai, bi, ci, nh;
bool big;
vector<vector<int> > data;
pair<int, int> NP = {-1, -1};
struct Vertex{int left; int right; int prior; int lg; int rg; long long sq; long long ssq; int h; int counts;};
vector<Vertex> decart;
void update(int vertex){
    if (vertex == -1){
        return;
    }
    int c = 1;
    long long ss = decart[vertex].sq;
    if (decart[vertex].left != -1){
        c += decart[decart[vertex].left].counts;
        ss += decart[decart[vertex].left].ssq;
    }
    if (decart[vertex].right != -1){
        c += decart[decart[vertex].right].counts;
        ss += decart[decart[vertex].right].ssq;
    }
    decart[vertex].ssq = ss;
    decart[vertex].counts = c;
}
pair<int, int> split(int f, int k){
    if (f == -1){
        return NP;
    }
    int l;
    if (decart[f].left == -1) l = 0;
    else l = decart[decart[f].left].counts;
    if (l >= k){
        pair<int, int> p = split(decart[f].left, k);
        decart[f].left = p.second;
        update(f);
        p.second = f;
        return p;
    }
    pair<int, int> p = split(decart[f].right, k - l - 1);
    decart[f].right = p.first;
    p.first = f;
    update(f);
    return p;
}
int merges(int first, int second){
    if (first == -1){
        return second;
    }
    if (second == -1){
        return first;
    }
    if (decart[first].prior > decart[second].prior){
        decart[first].right = merges(decart[first].right, second);
        update(first);
        update(second);
        return first;
    }
    decart[second].left = merges(first, decart[second].left);
    update(first);
    update(second);
    return second;
}
int get(int vertex, int number){
    if (vertex == -1) return 0;
    if (decart[vertex].rg < number){
        int l = 1;
        if (decart[vertex].left != -1) l += decart[decart[vertex].left].counts;
        return l + get(decart[vertex].right, number);
    }
    else{
        return get(decart[vertex].left, number);
    }
}
int get2(int vertex, int number){
    if (vertex == -1) return 0;
    if (decart[vertex].h >= number){
        int l = 1;
        if (decart[vertex].left != -1) l += decart[decart[vertex].left].counts;
        return l + get2(decart[vertex].right, number);
    }
    else{
        big = true;
        return get2(decart[vertex].left, number);
    }
}
int get_r(int vertex){
    if (vertex == -1) return 0;
    if (decart[vertex].right == -1) {nh=decart[vertex].h; return decart[vertex].rg;}
    return get_r(decart[vertex].right);
}
int get_l(int vertex){
    if (vertex == -1) return 0;
    if (decart[vertex].left == -1) {nh=decart[vertex].h; return decart[vertex].lg;}
    return get_l(decart[vertex].left);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> q >> r;
    int prefix[n+1][2];
    for (int i=0;i<n;i++){
        cin >> ai >> bi >> ci;
        vector<int> help;
        help.push_back(ai); help.push_back(bi); help.push_back(ci);
        data.push_back(help);
    }
    prefix[n][0] = 0; prefix[n][1] = 0;
    sort(data.begin(), data.end());
    int m1 = 0, m2 = 0;
    for (int i=n-1;i>=0;i--){
        m1 = max(m1, data[i][1]);
        m2 = max(m2, data[i][2]);
        prefix[i][0] = m1;
        prefix[i][1] = m2;
    }
    long long ans = 0;
    Vertex vv;
    vv.left = -1; vv.right = -1; vv.prior = rand() * rand(); vv.lg = 0; vv.rg = q; vv.counts = 1; vv.sq = 0; vv.ssq = 0; vv.h = 0;
    decart.push_back(vv);
    int base = 0;
    int u = 0;
    nh = 0;
    for (int i=1;i<=p;i++){
        while (u < n && data[u][0] < i) {
            int number = get(base, data[u][1]) + 1;
            pair<int, int> p = split(base, number);
            big = false;
            int hget = get2(p.first, data[u][2]);
            pair<int, int> p1 = split(p.first, hget);
            if (p1.second == -1){
                base = merges(p1.first, p.second); u++; continue;
            }
            Vertex vv;
            vv.left = -1; vv.right = -1; vv.prior = rand() * rand(); vv.lg = get_r(p1.first); vv.rg = data[u][1]; vv.counts = 1; vv.h = data[u][2]; vv.sq = ((long long)vv.rg - (long long) vv.lg) * (long long) vv.h; vv.ssq = vv.sq;
            decart.push_back(vv);
            base = decart.size() - 1;
            int gg = get_r(p1.second);
            int save = vv.rg;
            if (gg > vv.rg){
                Vertex vv;
                vv.left = -1; vv.right = -1; vv.prior = rand() * rand(); vv.lg = save; vv.rg = gg; vv.counts = 1; vv.h = nh; vv.sq = ((long long)vv.rg - (long long) vv.lg) * (long long) vv.h; vv.ssq = vv.sq;
                decart.push_back(vv);
                base = merges(base, decart.size() - 1);
            }
            base = merges(p1.first, base); base = merges(base, p.second);
            u++;
        }
        int m1 = prefix[u][0]; int m2 = prefix[u][1];
        int number = get(base, m1);
        pair<int, int> p = split(base, number);
        int number2 = get2(p.second, m2);
        pair<int, int> p1 = split(p.second, number2);
        long long zap = 0;
        if (p1.first != -1) {
            int ll = get_l(p1.first);
            int nnh = nh;
            zap = decart[p1.first].ssq - (long long) m2 * ((long long) get_r(p1.first) - (long long)ll);
            zap -= ((long long) nnh - (long long)m2) * ((long long)m1 - (long long)ll);
        }
        ans += ((long long)q - (long long)m1) * ((long long)r - (long long)m2) - zap;
        base = merges(p1.first, p1.second);
        base = merges(p.first, base);
    }
    cout << ans << endl;
    return 0;
}