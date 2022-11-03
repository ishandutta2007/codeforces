#include <bits/stdc++.h>
using namespace std;

void Fill(string& s, int l, int r, int sum)
{
    for (int i = r; i >= l; --i) {
        int c = min(sum, 9);
        s[i] = (char)(c + '0');
        sum -= c;
    }
}

string GetNumberWithSumOfDigits(int len, int sum)
{
    string r;
    r.resize(len);
    if (len == 1) {
        r[0] = (char)(sum + '0');
        return r;
    }
    if ((len - 1) * 9 < sum) {
        int c = sum - (len - 1) * 9;
        r[0] = (char)(c + '0');
        sum -= c;
        Fill(r, 1, len - 1, sum);
        return r;
    } else {
        r[0] = '1';
        sum -= 1;
        Fill(r, 1, len - 1, sum);
        return r;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s = "0";
    
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        
        int len = s.length();
        if (len * 9 >= b) {
            string cur = "";
            for (int gpos = 0; gpos < len; ++gpos) {
                if (s[gpos] == '9') {
                    continue;
                }
                int cb = b;
                for (int pos = 0; pos < gpos; ++pos) {
                    cb -= (s[pos] - '0');
                }
                if (cb < 0) {
                    continue;
                }
                for (char c = s[gpos] + 1; c <= '9'; ++c) {
                    int nc = c - '0';
                    
                    int ccb = cb - nc;
                    if (ccb >= 0 && ccb <= 9 * (len - gpos - 1)) {
                        string new_cur;
                        new_cur.resize(len);
                        for (int j = 0; j < gpos; ++j) {
                            new_cur[j] = s[j];
                        }
                        new_cur[gpos] = c;
                        Fill(new_cur, gpos + 1, len - 1, ccb);
                        
                        if (cur == "" || new_cur < cur) {
                            cur = new_cur;
                        }
                    }
                }
            }
            if (cur != "") {
                s = cur;
                cout << s << endl;
                continue;
            }
            ++len;
        }
        while (len * 9 < b) {
            ++len;
        }
        s = GetNumberWithSumOfDigits(len, b);
        cout << s << endl;
    }
    return 0;
}