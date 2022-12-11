#include <iostream>
#include <map>
#include <string>
using namespace std;
#define MAXN 110
map<string, int> m1, m2;
int n;
string t;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t, ++m1[t];
    for (int i = 1; i <= n; ++i) cin >> t, ++m2[t];
    int cnt = 0;
    for (map<string, int>::iterator it = m1.begin(); it != m1.end(); ++it)
        cnt += min(it -> second, m2[it -> first]);
    cout << n - cnt;
    return 0;    
}