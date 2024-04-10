#include <cstdio>
#include <cstring>
#include <cmath>

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

int n;
int a, b;


int main() {
    ios_base::sync_with_stdio(false); 
    for (cin >> n; n; --n) {
        cin >> a >> b;
        int cnt = 0;
        while (a > 0 && b > 0) {
            if (b > a) swap(a, b);
            int c = (a - b + 1) / b;
            if (c * b < a - b + 1) ++c;
            a -= c * b;
            cnt += c;
        }
        cout << cnt << endl;
    }
    return 0;
}