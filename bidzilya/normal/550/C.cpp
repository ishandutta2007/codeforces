#include <bits/stdc++.h>
using namespace std;

#define prev prev1829038109238

const int kMaxN = 100;

bool is[kMaxN][8];
bool need[kMaxN][8];
int prev[kMaxN][8];
vector<int> a;

void Show(int i, int j)
{
    if (prev[i][j] != -1) {
        Show(i - 1, prev[i][j]);
    }
    if (need[i][j]) {
        cout << a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            cout << "YES" << endl;
            cout << 0 << endl;
            return 0;
        }
    }
    
    is[0][a[0] % 8] = true;
    need[0][a[0] % 8] = true;
    prev[0][a[0] % 8] = -1;
    
    for (int i = 0; i + 1 < n; ++i) {
        is[i + 1][a[i + 1] % 8] = true;
        need[i + 1][a[i + 1] % 8] = true;
        prev[i + 1][a[i + 1] % 8] = -1;
        
        for (int rm = 0; rm < 8; ++rm) {
            if (!is[i][rm]) {
                continue;
            }
            
            is[i + 1][rm] = true;
            need[i + 1][rm] = false;
            prev[i + 1][rm] = rm;
            
            int new_rm = (rm * 10 + a[i + 1]) % 8;
            is[i + 1][new_rm] = true;
            need[i + 1][new_rm] = true;
            prev[i + 1][new_rm] = rm;
        }
    }
    
    if (is[n - 1][0]) {
        cout << "YES" << endl;
        Show(n - 1, 0);
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
   
    return 0;
}