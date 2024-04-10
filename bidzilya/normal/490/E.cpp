#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

const int pw10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

void ConstructString(string& s, int number)
{
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (pw10[n - i - 1] * j <= number) {
                number -= pw10[n - i - 1] * j;
                s[i] = (char) (j + '0');
                break;
            }
        }
    }
}

void FillQuestion(string& to, const string& from, const string& q)
{
    for (int i = 0, j = 0; i < (int) from.size(); ++i) {
        if (from[i] != '?') {
            to[i] = from[i];
        } else {
            to[i] = q[j];
            ++j;
        }
    }
}

bool IsGreater(const string& s1, const string& s2)
{
    if (s1.length() > s2.length()) {
        return true;
    }
    if (s1.length() < s2.length()) {
        return false;
    }
    
    for (int i = 0; i < (int) s1.length(); ++i) {
        if (s1[i] > s2[i]) {
            return true;
        }
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    
    return false;
}

bool DoStepOver(string& s, const string& t)
{
    int num_of_q = 0;
    for (int i = 0; i < (int) t.length(); ++i) {
        if (t[i] == '?') {
            ++num_of_q;
        }
    }
    
    string result;
    result.resize(t.length());
    string new_t;
    new_t.resize(t.length());
    string q;
    q.resize(num_of_q);
    
    int bl = 0;
    int br = pw10[num_of_q] - 1;
    
    if (t[0] == '?') {
        bl = pw10[num_of_q - 1];
    }
    
    bool found = false;
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        
        ConstructString(q, bm);
        
        FillQuestion(new_t, t, q);
        
        if (IsGreater(new_t, s)) {
            result = new_t;
            found = true;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }
    
    s = result;
    return found;
}


int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s = "0";
    
    vector<string> ans(n);
    
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        
        if (!DoStepOver(s, t)) {
            cout << "NO" << endl;
            return 0;
        }
        
        ans[i] = s;
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}