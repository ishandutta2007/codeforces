#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000011, inf = 1000111222;

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int number) {
    for (int i = number + 1; ; ++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const int DEFAULT_BASE[] = {next_prime(300 + rnd(5000)),
                            next_prime(300 + rnd(5000))};
const int DEFAULT_MOD = next_prime(1000000000 + rnd(100000));

class HashInt {
public:
    HashInt() {
    }

    HashInt(const string &s, char min_c = 'a', int
            base = DEFAULT_BASE[0], int mod = DEFAULT_MOD): mod(mod), h(s.length()), pw(s.length()) {

        pw[0] = 1;
        for (int i = 1; i < s.length(); ++i) {
            pw[i] = (1LL * pw[i - 1] * base) % mod;
        }
        h[0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h[i] = (1LL * h[i - 1] * base + s[i] - min_c + 1) % mod;
        }
    }

    int get_hash(int l, int r) const {
        if (!l) {
            return h[r];
        }
        return ((h[r] - 1LL * h[l - 1] * pw[r - l + 1]) % mod + mod) % mod;
    }

private:
    vector<int> h, pw;
    int mod;
};

class HashLong {
public:
    HashLong() {
    }

    HashLong(const string &s, char min_c = 'a', int base = DEFAULT_BASE[0]): h(s.length()), pw(s.length()) {
        pw[0] = 1;
        for (int i = 1; i < s.length(); ++i) {
            pw[i] = pw[i - 1] * base;
        }
        h[0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h[i] = h[i - 1] * base + s[i] - min_c + 1;
        }
    }

    long long get_hash(int l, int r) const {
        if (!l) {
            return h[r];
        }
        return h[r] - h[l - 1] * pw[r - l + 1];
    }

private:
    vector<long long> h, pw;
};

class Hash {
public:
    Hash() {
    }

    Hash(const string &s, char min_c = 'a',
         int base1 = DEFAULT_BASE[0], int base2 = DEFAULT_BASE[1],
         int mod = DEFAULT_MOD): h1(s, min_c, base1), h2(s, min_c, base2, mod) {
    }

    pair<long long, int> get_hash(int l, int r) {
        return {h1.get_hash(l, r), h2.get_hash(l, r)};
    }

private:
    HashLong h1;
    HashInt h2;
} h, hr;


char buf[max_n];
int n;
string s;

bool is_pal(int l, int r) {
    return h.get_hash(l, r) == hr.get_hash(n - r - 1, n - l - 1);
}

string read_str() {
    scanf("%s", buf);
    return buf;
}

string solve() {
    if (is_pal(0, n - 1)) {
        return s;
    }
    int mxc = 0;
    for (int i = 0; i < n; ++i) {
        int j = n - i - 1;
        if (j <= i) {
            break;
        }
        if (s[i] != s[j]) {
            break;
        }
        mxc = i + 1;
    }
    int mxp = 0;
    int l = mxc, r = n - mxc - 1;
    for (int k = r; k >= l; --k) {
        if (is_pal(k, r)) {
            mxp = r - k + 1;
        }
    }
    int BP, BM, B;
    BP = mxc;
    BM = mxp;
    B = BP * 2 + BM;
    for (int bp = mxc - 1; bp >= 0; --bp) {
        --l;
        ++r;
        int curp = mxp + 2;
        while(!is_pal(r - curp + 1, r)) {
            --curp;
        }
        mxp = curp;
        if (bp * 2 + mxp > B) {
            B = bp * 2 + mxp;
            BP = bp;
            BM = mxp;
        }
    }
    string res;
    for (int i = 0; i < BP; ++i) {
        res += s[i];
    }
    for (int i = 0; i < BM; ++i) {
        res += s[n - BP - BM + i];
    }
    for (int i = 0; i < BP; ++i) {
        res += s[n - BP + i];
    }
    return res;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        s = read_str();
        n = s.size();
        h = Hash(s);
        reverse(s.begin(), s.end());
        hr = Hash(s);
        reverse(s.begin(), s.end());
        string s1 = solve();
        swap(h, hr);
        reverse(s.begin(), s.end());
        string s2 = solve();
        if (s1.size() > s2.size()) {
            printf("%s\n", s1.c_str());
        } else {
            printf("%s\n", s2.c_str());
        }
    }

    return 0;
}