#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int NN = 600005;
const int T = 50;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<int> gen(0, 1000000007);

struct Fenwick {
    int arr[N];
    
    int sum(int r) {
        int res = 0;
        for (; r>=0; r = (r&(r+1))-1)
            res += arr[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int id, int x) {
        for(; id<N; id = (id|(id+1)))
            arr[id] += x;
    }
};

int n, q, nn;
int arr[N];
array<int, 4> queries[N];

bitset<NN> sets[T];
map<int, int> mp;
vector<int> stuff;
Fenwick trees[T];

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i<n; ++i)
        cin >> arr[i], stuff.push_back(arr[i]);
    for (int i = 0; i<q; ++i) {
        int type; cin >> type;
        if (type == 1) {
            int id, x;
            cin >> id >> x;
            --id;
            queries[i] = {1, id, x, 0};
            stuff.push_back(x);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            --l; --r;
            queries[i] = {2, l, r, k};
        }
    }
    
    sort(stuff.begin(), stuff.end());
    stuff.erase(unique(stuff.begin(), stuff.end()), stuff.end());
    nn = stuff.size();
    for (int i = 0; i<nn; ++i) {
        mp[stuff[i]] = i;
    }
    for(int i = 0; i<n; ++i) 
        arr[i] = mp[arr[i]];
    for (int i = 0; i<T; ++i) {
        for (int j = 0; j<nn; ++j) {
            if (gen(rng)&1) sets[i].set(j);
        }
    }
    for (int i = 0; i<T; ++i) {
        for (int j = 0; j<n; ++j) {
            if (sets[i][arr[j]]) {
                trees[i].add(j, 1);
            }
        }
    }
    
    for (int i = 0; i<q; ++i) {
        int type = queries[i][0];
        if (type == 1) {
            int id = queries[i][1], x = mp[queries[i][2]];
            for (int j = 0; j<T; ++j) {
                if (sets[j][arr[id]]) {
                    trees[j].add(id, -1);
                }
                if(sets[j][x]) {
                    trees[j].add(id, 1);
                }
            }
            arr[id] = x;
        } else {
            int l = queries[i][1], r = queries[i][2], k = queries[i][3];
            bool res = true;
            for(int j = 0; j<T; ++j) {
                if (trees[j].sum(l, r)%k != 0) {
                    res = false;
                    break;
                }
            }
            cout << (res ? "YES" : "NO") << '\n';
        }
    }
}