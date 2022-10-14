#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int tt = n;
    while(n--) {
        int i; cin >> i;
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    int l = 0, r = v.size()-1;
    long long x = 0, y = 0;
    for(int i=0; i<tt; i++) {
        if(i % 2) y += v[l++];
        else x += v[r--];
    }
    cout << x*x+y*y << endl;
}