/*
    > Author : LiM_817
*/

#include <bits/stdc++.h>

using namespace std;

const int Maxn = 10000 + 10;
int n;
string s[Maxn];

map < string , set <int> > v;
int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> s[i];
    
    for(int i = 1;i <= n;i++) {
        for(int lth = 1; lth <= s[i] . size(); lth++) {
            for(int l = 0; l < s[i] . size(); l++) {
                int r = l + lth - 1;
                if(r >= (int)s[i] . size()) continue;
                string x = s[i] . substr(l , lth);
                v[x] . insert(i);
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        string x;
        cin >> x;
        cout << v[x] . size() << " ";
        if(v[x] . size() == 0) cout << "-\n";
        else cout << s[*(v[x] . begin())] << endl;
    }
    return 0;
}