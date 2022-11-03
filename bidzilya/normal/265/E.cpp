#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 1e5 + 100;

ll val_cl[max_n];
int fnd_cl[max_n];
pair<ll, ll> val_max_cl;
pair<int, int> cl_max_cl;

int n;
int cl[max_n];
ll val[max_n];

int q;
ll a, b;

void shake() {
    if (val_max_cl.second > val_max_cl.first) {
        swap(val_max_cl.first, val_max_cl.second);
        swap(cl_max_cl.first, cl_max_cl.second);
    }
}

int main() { 
    ios_base::sync_with_stdio(false);  
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    for (int i = 0; i < n; ++i)
        cin >> cl[i];
    for (; q; --q) {
        cin >> a >> b;
        for (int i = 1; i <= n; ++i)
            fnd_cl[i] = 0;
        cl_max_cl.first = cl_max_cl.second = 0;
        val_max_cl.first = val_max_cl.second = 0;
        for (int i = 0; i < n; ++i) {
            if (fnd_cl[cl[i]]) {
                val_cl[cl[i]] = max(val_cl[cl[i]], val_cl[cl[i]] + a * val[i]);
                if (cl[i] == cl_max_cl.first) {
                    val_max_cl.first = val_cl[cl[i]];
                } else if (cl[i] == cl_max_cl.second) {
                    val_max_cl.second = val_cl[cl[i]];
                    shake();
                } else if (val_cl[cl[i]] > val_max_cl.second) {
                    val_max_cl.second = val_cl[cl[i]];
                    cl_max_cl.second = cl[i];
                    shake();
                }
            }
            if (cl[i] == cl_max_cl.first) {
                if (!fnd_cl[cl[i]]) {
                    val_cl[cl[i]] = val_max_cl.second + b * val[i];
                } else {
                    val_cl[cl[i]] = max(val_cl[cl[i]], val_max_cl.second + b * val[i]);
                }
            } else {
                if (!fnd_cl[cl[i]]) {
                    val_cl[cl[i]] = val_max_cl.first + b * val[i];
                } else {
                    val_cl[cl[i]] = max(val_cl[cl[i]], val_max_cl.first + b * val[i]);
                }
            }
            if (cl[i] == cl_max_cl.first) {
                val_max_cl.first = val_cl[cl[i]];
            } else if (cl[i] == cl_max_cl.second) {
                val_max_cl.second = val_cl[cl[i]];
                shake();
            } else if (val_cl[cl[i]] > val_max_cl.second) {
                val_max_cl.second = val_cl[cl[i]];
                cl_max_cl.second = cl[i];
                shake();
            }
            fnd_cl[cl[i]] = 1;
        }
        cout << val_max_cl.first << endl;
    }
    
    return 0;
}