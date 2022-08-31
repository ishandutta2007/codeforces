#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Vertex{int l; int r; int pr; int sz; int value; int Or;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    decart[vertex].Or = decart[vertex].value;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
        decart[vertex].Or |= decart[decart[vertex].l].Or;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
        decart[vertex].Or |= decart[decart[vertex].r].Or;
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
int gt(int base, int bt){
    int L = decart[base].l, R = decart[base].r;
    if (L==-1){
        int ba = decart[base].value & (1LL<<bt);
        if (ba != 0) return 0;
        return 1 + gt(R, bt);
    }
    int ba = decart[L].Or & (1LL<<bt);
    if (ba != 0) return gt(L, bt);
    int sz = decart[L].sz;
    ba = decart[base].value & (1LL<<bt);
    if (ba != 0) return sz;
    return sz+1+gt(R, bt);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int base = -1;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<vector<int> > oldest(60);
    for (int i=0; i < n; i++){
        for (int j=59; j >= 0; j--){
            int ba = v[i] & (1LL<<j);
            if (ba==0) continue;
            oldest[j].push_back(v[i]);
            break;
        }
    }
    for (int i=59; i >= 0; i--){
        int nb = -1;
        for (int j=1; j < oldest[i].size(); j++){
            int xx = oldest[i][j];
            if (base == -1){
                cout << "No";
                return 0;
            }
            int ba = decart[base].Or & (1LL<<i);
            if (ba==0){
                cout << "No";
                return 0;
            }
            int num = gt(base, i);
            pair<int, int> p = split(base, num+1);
            nb = merg(nb, p.first);
            Vertex nv = {-1, -1, rand(), 1, xx, xx};
            decart.push_back(nv);
            nb = merg(nb, decart.size()-1);
            base = p.second;
        }
        base = merg(nb, base);
        if (!oldest[i].size()) continue;
        int xx = oldest[i][0];
        Vertex nv = {-1, -1, rand(), 1, xx, xx};
        decart.push_back(nv);
        base = merg(decart.size() - 1, base);
    }
    cout << "Yes" << endl;
    for (int i=0; i < n; i++){
        pair<int, int> p = split(base, 1);
        cout << decart[p.first].value << " ";
        base = p.second;
    }
    return 0;
}