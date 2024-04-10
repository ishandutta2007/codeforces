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

string s1, s2;
int c1, c2;

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> s1 >> s2;    
    for (int i = 0; i < s1.length(); ++i)
        c1 += s1[i] - '0';
    for (int i = 0; i < s2.length(); ++i)
        c2 += s2[i] - '0';
    if (c1 % 2 == 1) ++c1;
    if (c1 >= c2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}