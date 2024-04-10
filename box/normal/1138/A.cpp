#include <bits/stdc++.h>
using namespace std;

vector<int> a;
    
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while(n--) { int v; cin >> v; a.push_back(v); }
    int ones = 0, twos = 0, best = 0;
    for(int v:a) {
        if(twos == 0) {
            if(v == 1) ones++;
            else twos++;
        } else {
            if(v == 2) twos++;
            else {
                best = max(best, 2*min(ones, twos));
                ones = 1; twos = 0;
            }
        }
    }
    reverse(a.begin(), a.end());
    int best1 = max(best, 2*min(ones, twos));
    ones = 0, twos = 0, best = 0;
    for(int v:a) {
        if(twos == 0) {
            if(v == 1) ones++;
            else twos++;
        } else {
            if(v == 2) twos++;
            else {
                best = max(best, 2*min(ones, twos));
                ones = 1; twos = 0;
            }
        }
    }
    cout << max(best1, max(best, 2*min(ones, twos))) << endl;
}