#include <bits/stdc++.h>
using namespace std;
set<char> s;

int main() {
    string n; cin >> n;
    for(int i = 0; i < n.length(); ++i)
        s.insert(n[i]);

    puts(s.size()&1? "IGNORE HIM!" : "CHAT WITH HER!");

   return 0;
}