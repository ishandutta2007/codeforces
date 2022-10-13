#include <bits/stdc++.h>

using namespace std;

int GetBit(int no, int bit) {
    return ((no >> bit) & 1);
}

struct Trie {
    
    struct Node {
        int cnt = 0;
        int leg[2] = {0, 0};
    };
    vector<Node> T;

    Trie() : T(2) {};
    
    int alloc() {
        int ret = T.size();
        T.emplace_back();
        return ret;
    }

    int Add(int no) {
        int node = 1;
        for (int i = 29; i >= 0; --i) {
            int bit = GetBit(no, i);
            if (T[node].leg[bit] == 0) {
                int nw = alloc();
                T[node].leg[bit] = nw;
            }
            node = T[node].leg[bit];
            T[node].cnt += 1;
        }
        return node;
    }

    void Remove(int no) {
        int node = 1;
        for (int i = 29; i >= 0; --i) {
            int bit = GetBit(no, i);
            node = T[node].leg[bit];
            assert(node != 0);
            T[node].cnt -= 1;
        }
    } 

    int MinXor(int no) {
        int node = 1;
        int ret = 0;
        for (int i = 29; i >= 0; --i) {
            int bit = GetBit(no, i);
            if (T[T[node].leg[bit]].cnt > 0)
                node = T[node].leg[bit];
            else {
                assert(T[T[node].leg[bit ^ 1]].cnt > 0);
                ret |= (1 << i);
                node = T[node].leg[bit ^ 1];
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    Trie T;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        T.Add(x);
    }

    for (int i = 0; i < n; ++i) {
        int res = T.MinXor(a[i]);
        cout << res << " ";
        T.Remove(res ^ a[i]);
    }
    cout << endl;

    return 0;
}