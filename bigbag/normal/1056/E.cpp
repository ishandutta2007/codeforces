#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

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

class Hash {
public:
    Hash() {
    }

    Hash(const std::string &str, char min_c = 'a') {
        srand(chrono::steady_clock::now().time_since_epoch().count());
        int p_first = next_prime(100 + rand() % 200);
        int p_second = next_prime(100 + rand() % 200);
        mod = next_prime(1000000000 + rand() % 10000);

        h_first.resize(str.length());
        h_second.resize(str.length());
        pw_first.resize(str.length());
        pw_second.resize(str.length());

        pw_first[0] = 1;
        pw_second[0] = 1;
        for (int i = 1; i < str.length(); ++i) {
            pw_first[i] = pw_first[i - 1] * p_first;
            pw_second[i] = (1LL * pw_second[i - 1] * p_second) % mod;
        }

        h_first[0] = str[0] - min_c + 1;
        h_second[0] = str[0] - min_c + 1;
        for (int i = 1; i < str.length(); ++i) {
            h_first[i] = h_first[i - 1] * p_first + str[i] - min_c + 1;
            h_second[i] = (1LL * h_second[i - 1] * p_second + str[i] - min_c + 1) % mod;
        }
    }

    void operator = (const std::string &str) {
        *this = Hash(str);
    }

    std::pair<long long, int> get_hash(int left, int right) {
        long long first = h_first[right], second = h_second[right];
        if (left) {
            first -= h_first[left - 1] * pw_first[right - left + 1];
            second -= (1LL * h_second[left - 1] * pw_second[right - left + 1]) % mod;
            if (second < 0) {
                second += mod;
            }
        }
        return {first, second};
    }

private:
    std::vector<long long> h_first, pw_first;
    std::vector<int> h_second, pw_second;
    int mod;
};

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int c0, c1, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s = read();
    string t = read();
    Hash h(t);
    for (int i = 0; i < s.length(); ++i) {
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    for (int l0 = 1; c0 * l0 < t.length(); ++l0) {
        int l1 = t.length() - c0 * l0;
        if (l1 % c1) {
            continue;
        }
        l1 /= c1;

        pair<long long, int> ok[2];
        bool was[2];
        int len[2];
        was[0] = was[1] = false;
        len[0] = l0;
        len[1] = l1;

        int cur = 0;
        bool res = true;
        for (int i = 0; i < s.length(); ++i) {
            int tp = s[i] - '0';
            if (!was[tp]) {
                was[tp] = true;
                ok[tp] = h.get_hash(cur, cur + len[tp] - 1);
            } else if (ok[tp] != h.get_hash(cur, cur + len[tp] - 1)) {
                res = false;
                break;
            }
            cur += len[tp];
        }
        if (res && ok[0] != ok[1]) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}