#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 1e6 + 10;
const int max_c = 26 + 10 + 3;

char s[max_n];
int sm[max_n][max_c];
int n;

int cs[max_c];

void get_cs(int l, int r)
{
    for (int i = 0; i < max_c; ++i)
        cs[i] = sm[r][i];
    if (l > 0) {
        for (int i = 0; i < max_c; ++i)
            cs[i] -= sm[l - 1][i];
    }
}

int char_to_int(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    if (c >= '0' && c <= '9')
        return c - '0' + 26;
    if (c == '.') return 36;
    if (c == '_') return 37;
    if (c == '@') return 38;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%s\n", s);
    n = strlen(s);

    for (int i = 0; i < max_c; ++i) 
        sm[0][i] = 0;
    ++sm[0][char_to_int(s[0])];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < max_c; ++j)
            sm[i][j] = sm[i - 1][j];
        ++sm[i][char_to_int(s[i])];
    }
    
    ll ans = 0;
    for (int i = 0; i < n; )
        if (s[i] == '@') {
            bool good = true;
            int j = i + 1;
            while (j < n && s[j] != '.') {
                if (s[j] == '_' || s[j] == '@') {
                    good = false;
                    break;
                }
                ++j;
            }
            if (j == n) break;
            if (j == i + 1) {
                ++i;
                continue;
            }
            if (!good) {
                ++i;
                continue;
            }
            
            int left_len = -1;
            int bl = 0, br = i - 1;
            while (bl <= br) {
                int bm = (bl + br) >> 1;
                get_cs(bm, i - 1);
                if (cs[char_to_int('.')] == 0 && cs[char_to_int('@')] == 0) {
                    left_len = bm;
                    br = bm - 1;
                } else {
                    bl = bm + 1;
                }
            }
            if (left_len == -1) {
                ++i;
                continue;
            }
            
            int left_sum = 0;
            for (char c = 'a'; c <= 'z'; ++c)
                left_sum += cs[char_to_int(c)];
            
            int right_len = -1;
            bl = j + 1, br = n - 1;
            while (bl <= br) {
                int bm = (bl + br) >> 1;
                get_cs(j + 1, bm);
                good = true;
                for (int c = 26; c < max_c; ++c)
                    if (cs[c] != 0) {
                        good = false;
                        break;
                    }
                if (good) {
                    right_len = bm;
                    bl = bm + 1;
                } else {
                    br = bm - 1;
                }
            }
            if (right_len == -1) {
                ++i;
                continue;
            }
            
            int right_sum = right_len - j;
            
            ans += 1LL * left_sum * right_sum;
            ++i;
        } else {
            ++i;
        }
        
    cout << ans << endl;
    return 0;
}