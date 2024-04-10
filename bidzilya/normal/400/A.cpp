#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef long long ll;

char s[20];

bool check(int a, int b) {
    for (int stl = 0; stl < b; ++stl) {
        bool good = true;
        for (int itr = 0; itr < a; ++itr)
            if (s[(stl + itr * b) % 12] != 'X') {
                good = false;
                break;
            }
        if (good)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    int test;
    for (cin >> test; test; --test) {
        cin >> s;
        
        vector<pair<int, int> > ar;
        for (int a = 1; a <= 12; ++a) 
            if (12 % a == 0) {
                int b = 12 / a;
                if (check(a, b)) {
                    ar.push_back(make_pair(a, b));
                }
            }
        sort(ar.begin(), ar.end());
        cout << ar.size() << " ";
        for (int i = 0; i < ar.size(); ++i)
            cout << ar[i].first << "x" << ar[i].second << " ";
        cout << endl;
    }

    
    return 0;
}