#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

unordered_set<string> res_tok;

enum Type {
    NONE,
    RES,
    NUM,
    WORD,
};

Type chk(const string &s) {
    if (res_tok.count(s))
        return RES;
    if (!SZ(s))
        return NONE;
    bool is_word = 1, is_num = 1;
    for (char c : s) {
        if (!isdigit(c))
            is_num = 0;
        if (!isdigit(c) && !isalpha(c) && c != '_' && c != '$')
            is_word = 0;
    }
    if (is_num)
        return NUM;
    if (!isdigit(s[0]) && is_word)
        return WORD;
    return NONE;
}

void adv(string &s) {
    reverse(ALL(s)); 
    int i = 0;
    while (i < SZ(s) && s[i] == 'z') {
        s[i] = 'a';
        ++i;
    }
    if (i < SZ(s))
        s[i]++;
    else
        s.pb('a');
    reverse(ALL(s));
}

unordered_map<string, string> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n_res_tok;
    cin >> n_res_tok;
    for (string s; n_res_tok > 0; n_res_tok--) {
        cin >> s;
        res_tok.insert(s);
    }
    vector<string> toks;
    int lines;
    cin >> lines;
    cin.ignore();
    for (string s; lines > 0; --lines) {
        getline(cin, s);
        int comit = 0;
        while (comit < SZ(s) && s[comit] != '#')
            ++comit;
        s = s.substr(0, comit);
        for (int i = 0; i < SZ(s); ) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            int j = SZ(s);
            Type tp = NONE;
            while (j != i && (tp = chk(s.substr(i, j - i))) == NONE)
                --j;
            assert(tp != NONE);
            toks.pb(s.substr(i, j - i));
            i = j;
        }
    }
    string nxt = "a";
    for (auto &s : toks) {
        auto tp = chk(s);
        if (tp == WORD) {
            auto it = mp.find(s);
            if (it != mp.end())
                s = mp[s];
            else {
                while (res_tok.count(nxt))
                    adv(nxt);
                s = mp[s] = nxt;
                adv(nxt);
            }
        }
    }
    string ans = "", cur = "";
    reverse(ALL(toks)); 
    for (auto &s : toks) {
        auto tp = chk(s);
        assert(tp != NONE);
        bool ok = 1;
        for (int i = 1; i <= 20 && i <= SZ(cur); i++) {
            auto tp2 = chk(s + cur.substr(0, i)); 
            if (tp2 != NONE)
                ok = 0;
        }
        if (ok)
            ans = s + ans, cur = s + cur;
        else
            ans = s + " " + ans, cur = s;
    }
    cout << ans << endl;
}