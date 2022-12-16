#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const ull PRIME = 210233;
const ull MOD = 105517331;

ull mpow(ull base, ull amt) {
    ull ans = 1;
    ull one = 1;
    ull val = base;
    for(int i=0;i<64;++i, val = (val*val)%MOD) {
        if((one<<i) & amt) {
            ans = (ans*val)%MOD;
        }
    }
    return ans;
}

char bit_arr[200010][26];
ull pfx_hash[200010][26];

void setup_hash(string s) {
    for(size_t i=0;i<s.size();++i) {
        bit_arr[i][s[i]-'a'] = 1;
    }
    for(int n=0;n<26;++n) {
        pfx_hash[0][n] = 0;
    }
    for(size_t i=0;i<s.size();++i) {
        for(size_t n=0;n<26;++n) {
            pfx_hash[i+1][n] = (pfx_hash[i][n] * PRIME + bit_arr[i][n]) % MOD;
        }
    }
}

ull get_hash(int num, int l, int r) {
    return (pfx_hash[r][num] - (mpow(PRIME, (r-l))*pfx_hash[l][num])%MOD + MOD)%MOD;
}

int next_char[200010][26];

void setup_next(string s) {
    int sn_next[26];
    for(int i=0;i<26;++i) {
        sn_next[i] = s.size();
    }
    for(int i=s.size()-1;i>=0;--i) {
        sn_next[s[i]-'a'] = i;
        for(int j=0;j<26;++j) {
            next_char[i][j] = sn_next[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M;
    string s;
    cin >> N;
    cin >> M;
    cin >> s;
    setup_hash(s);
    setup_next(s);

    for(int q=0;q<M;++q) {
        int x, y, len;
        cin >> x;
        cin >> y;
        cin >> len;
        int xl = x-1;
        int xr = x+len-1;
        int yl = y-1;
        int yr = y+len-1;

        int yoffset = y-x;
        bool good = true;

        //cerr << xl << " " << xr << ",, " << yl << " " << yr << endl;
        for(int i=0;i<26;++i) {
            if(next_char[xl][i] < xr) {
                int ychar = s[next_char[xl][i] + yoffset]-'a';
                //cerr << "  x = " << i << ", y = " << ychar << " : " << get_hash(i, xl, xr) << " " << get_hash(ychar, yl, yr) << endl;
                if(!(get_hash(i, xl, xr) == get_hash(ychar, yl, yr))) {
                    good = false;
                    break;
                }
            }
        }
        cout << (good ? "YES" : "NO" ) << "\n";
    }
    return 0;
}