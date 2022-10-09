#include<bits/stdc++.h>
using namespace std;

/**
 * Author: Simon Lindholm
 * Date: 2016-07-23
 * License: CC0
 * Source: me
 * Description: BumpAllocator for STL containers.
 * Usage: vector<vector<int, small<int>>> ed(N);
 * Status: tested
 */
#pragma once

char buf[100 << 20] alignas(16);
size_t buf_ind = sizeof buf;

template<class T> struct small {
	typedef T value_type;
	small() {}
	template<class U> small(const U&) {}
	T* allocate(size_t n) {
		buf_ind -= n * sizeof(T);
		buf_ind &= 0 - alignof(T);
		return (T*)(buf + buf_ind);
	}
	void deallocate(T*, size_t) {}
};


const int inf = (int)1e7;
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int, small<int>> a(n);
        for (auto& i: a) cin >> i;
        
        int first_eq = 0;
        while (first_eq + 1 < n and a[first_eq] != a[first_eq + 1]) ++ first_eq;
        if (first_eq + 1 == n) {
            cout << "0\n";
            continue;
        }
        int last_eq = n - 2;
        while (last_eq >= 0 and a[last_eq] != a[last_eq + 1]) --last_eq;
        if (first_eq == last_eq) {
            cout << "0\n";
            continue;
        }
        cout << max(last_eq - first_eq - 1, 1) << '\n';
    }
    
    return 0;
}