#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "cassert"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define EPS 1e-11
typedef long long int ll;
typedef long double ld;
using namespace std;
void sv(){
    int n, m;
    cin >> n >> m;
    vector<int> c(m), k(n);
    for (auto &i : k)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    sort(rall(k));
    ll res = 0;
    int v = 1;
    for (int i = 0; i < n; ++i) {
        if (v <= k[i]){
            res += c[v-1];
            v++;
        }else{
            res += c[k[i] - 1];
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        sv();
    }
}