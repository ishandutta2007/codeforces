#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

string s;
int n;

bool good(char c) {
    return (c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e');
}

vector<int> bad_pos, spc;

int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < n - 2; ++i) {
        if ((s[i] != s[i+1] || s[i+1] != s[i+2]) && (!good(s[i])) && (!good(s[i+1])) && (!good(s[i+2])))
            bad_pos.push_back(i);
    }
    for (auto pos : bad_pos) {
        if (spc.empty() || spc.back() < pos)
            spc.push_back(pos + 1);
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        cout << s[i];
        if (ptr < spc.size() && spc[ptr] == i) {
            cout << ' ';
            ptr++;
        }
    }
    cout << endl;
    return 0;
}