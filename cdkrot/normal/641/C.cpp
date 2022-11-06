#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;

#define PYMOD(A, M) ((((A) % (M)) + (M)) % (M))

char buf[200];

pair<int, int> input_two() {
    fgets(buf, sizeof(buf), stdin);
    int p_sp = std::find(buf, buf + sizeof(buf), ' ') - buf;
    return make_pair(std::atoi(buf), std::atoi(buf + p_sp + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    std::tie(n, q) = input_two();
    ll base = 0;
    ll even = 0;
    for (int i = 0; i < q; i++) {
        fgets(buf, sizeof(buf), stdin);
        
        int type = std::atoi(buf);
        if (type == 1) {
            int p_sp = std::find(buf, buf + sizeof(buf), ' ') - buf;
            ll tmp = std::atoll(buf + p_sp + 1);
            base += tmp;
        } else {
            if ((base + even) % 2 == 0)
                even++;
            else
                even--;
        }
    }
   
    int* ans = new int[n];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            ans[PYMOD(i + base + even, n)] = i; 
        else
            ans[PYMOD(i + base - even, n)] = i; 
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
    return 0;
}