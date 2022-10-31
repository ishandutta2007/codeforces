#include <bits/stdc++.h>
using namespace std;

const int N = 2048;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int n;

int query(int i, int j){
    cout << "? " << i+1 << " " << j+1 << endl;
    int a; cin >> a;
    return a;
}

int get(vector<int> pos){
    int m = pos.size();
    if(pos.size() == 2){
        int r1 = N, r2 = N;
        while(r1 == r2){
            int i = rng()%n;
            if(i == pos[0] || i == pos[1]) continue;
            r1 = query(i, pos[0]), r2 = query(i, pos[1]);
        }
        if(r1 < r2) return pos[0];
        return pos[1];
    }
    int id;
    if((int)pos.size() == n){
        int siz = min(7, n);
        vector<int> tmp(n);
        iota(tmp.begin(), tmp.end(), 0);
        shuffle(tmp.begin(), tmp.end(), rng);
        vector<int> lol;
        for(int i = 0; i<siz; i++)
            lol.push_back(tmp[i]);
        vector<int> cnt(siz, 0);
        for(int i = 0; i<siz; i++){
            for(int j = i+1; j<siz; j++){
                int v = __builtin_popcount(query(lol[i], lol[j]));
                cnt[i] += v, cnt[j] += v;
            }
        }
        id = lol[min_element(cnt.begin(), cnt.end())-cnt.begin()];
    } else id = rng()%m;
    int minval = N;
    vector<int> nxt;
    for(int i = 0; i<(int)pos.size(); i++){
        if(i == id) continue;
        int tmp = query(pos[id], pos[i]);
        if(tmp < minval){
            minval = tmp;
            nxt.clear(); nxt.push_back(pos[i]);
        } else if(tmp == minval) nxt.push_back(pos[i]);
    }
    nxt.push_back(pos[id]);
    return get(nxt);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; vector<int> tmp(n);
    iota(tmp.begin(), tmp.end(), 0);
    int v = get(tmp);
    vector<int> vals(n);
    for(int i = 0; i<n; i++)
        if(i == v) vals[i] = 0;
        else vals[i] = query(i, v);
    cout << "! ";
    for(int i = 0; i<n; i++)
        cout << vals[i] << " ";
    cout << endl;
}