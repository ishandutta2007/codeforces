#include <bits/stdc++.h>
using namespace std;

unordered_set<long long> used;

long long GetCode(const deque<int>& a, const deque<int>& b)
{
    long long r = a.size();
    int last_bit = 4;
    for (int i = 0; i < (int) a.size(); ++i) {
        r += (1LL << last_bit) * a[i];
        last_bit += 4;
    }
    for (int i = 0; i < (int) b.size(); ++i) {
        r += (1LL << last_bit) * b[i];
        last_bit += 4;
    }
    return r;
}

int n;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    int k1, k2;
    cin >> k1;
    deque<int> a1(k1);
    for (int i = 0; i < k1; ++i) {
        cin >> a1[i];
    }
    cin >> k2;
    deque<int> a2(k2);
    for (int i = 0; i < k2; ++i) {
        cin >> a2[i];
    }
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    a.resize(n);
    for (int i = 0; i < k1; ++i) {
        a[i] = a1[i];
    }
    for (int i = 0; i < k2; ++i) {
        a[k1 + i] = a2[i];
    }
    for (int i = 0; i < k1; ++i) {
        a1[i] = i;
    }
    for (int i = 0; i < k2; ++i) {
        a2[i] = k1 + i;
    }
    
    used.insert(GetCode(a1, a2));
    
    int fights = 0;
    while (true) {
        ++fights;
        int c1 = a1.back();
        int val1 = a[c1];
        a1.pop_back();
        int c2 = a2.back();
        int val2 = a[c2];
        a2.pop_back();
        if (val1 > val2) {
            a1.push_front(c2);
            a1.push_front(c1);
            if (a2.empty()) {
                cout << fights << " " << 1 << endl;
                return 0;
            }
        } else {
            a2.push_front(c1);
            a2.push_front(c2);
            if (a1.empty()) {
                cout << fights << " " << 2 << endl;
                return 0;
            }
        }
        long long cur_code = GetCode(a1, a2);
        if (used.find(cur_code) != used.end()) {
            cout << -1 << endl;
            return 0;
        }
        used.insert(cur_code);
    }
}