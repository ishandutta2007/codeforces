#include <bits/stdc++.h>
using namespace std;
int main() {
string s, t;
int k, n;
cin >> k;
while (k--)
cin >> n >> s >> t,
cout << ((bitset<100>(s) & bitset<100>(t)).count() ? "NO\n" : "YES\n");
}