#include <bits/stdc++.h>
 
#define F first
#define S second
 
using ll = long long;
 
using namespace std;
 
const int N = 300005, B = 31;
 
struct Node {
    int mx[2]{};
    Node *next[2]{};
    void insert(int a, int i, int v) {
        Node *current = this;
        int number = (a ^ i);
        for (int bit = B - 1; bit >= 0; --bit) {
            int b = ((number >> bit) & 1);
            if (current->next[b] == nullptr)
                current->next[b] = new Node;
            current = current->next[b];
            int &m = current->mx[(i >> bit) & 1];
            m = max(m, v);
        }
    }
    int query(int a, int i) const {
        int ret = 0, number = (a ^ i);
        const Node *current = this;
        for (int bit = B - 1; bit >= 0; --bit) {
            int b = ((number >> bit) & 1);
            int j = ((a >> bit) & 1);
            if (current->next[b ^ 1] != nullptr)
                ret = max(ret, current->next[b ^ 1]->mx[j ^ 1]);
            if (current->next[b] == nullptr)
                break;
            current = current->next[b];
        }
        return ret;
    }
    ~Node() {
        delete next[0];
        delete next[1];
    }
};
 
int n, a[N], dp[N];
 
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Node trie;
        for (int i = 0; i < n; ++i) {
            dp[i] = trie.query(a[i], i) + 1;
            trie.insert(a[i], i, dp[i]);
        }
        cout << *max_element(dp, dp + n) << '\n';
    }
    return 0;
}