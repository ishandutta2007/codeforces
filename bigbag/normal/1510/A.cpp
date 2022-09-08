/**
 *  created: 20/04/2021, 12:45:55
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

struct state {
    vector<string> v;

    int h() const {
        return v.size();
    }

    int w() const {
        return v[0].size();
    }

    friend ostream& operator << (ostream &os, const state &s) {
        os << s.h() << " " << s.w() << "\n";
        for (auto x : s.v) {
            os << x << "\n";
        }
        return os;
    }
};

state parse_expr(const string &s);

state only_letters(const string &s) {
    const int w = s.size() + 4;
    state res;
    string header(w, '-');
    header[0] = header.back() = '+';
    res.v.push_back(header);
    res.v.push_back("+ " + s + " +");
    res.v.push_back(header);
    return res;
}

state apply_plus(const state &s) {
    state res;
    for (int i = 0; i < s.v.size(); ++i) {
        if (i == 0) {
            res.v.push_back("   " + s.v[i] + "   ");
        } else if (i == 1) {
            res.v.push_back("+->" + s.v[i] + "->+");
        } else {
            res.v.push_back("|  " + s.v[i] + "  |");
        }
    }
    res.v.push_back("|  " + string(s.w(), ' ') + "  |");
    res.v.push_back("+<-" + string(s.w(), '-') + "--+");
    return res;
}

state apply_question(const state &s) {
    state res;
    res.v.push_back(string(s.w() + 6, ' '));
    res.v.push_back("+--" + string(s.w(), '-') + "->+");
    res.v.push_back("|  " + string(s.w(), ' ') + "  |");
    for (int i = 0; i < s.v.size(); ++i) {
        if (i == 1) {
            res.v.push_back("+->" + s.v[i] + "->+");
        } else if (i == 0) {
            res.v.push_back("|  " + s.v[i] + "  |");
        } else {
            res.v.push_back("   " + s.v[i] + "   ");
        }
    }
    return res;
}

state apply_star(const state &s) {
    state res;
    res.v.push_back(string(s.w() + 6, ' '));
    res.v.push_back("+--" + string(s.w(), '-') + "->+");
    res.v.push_back("|  " + string(s.w(), ' ') + "  |");
    for (int i = 0; i < s.v.size(); ++i) {
        if (i == 1) {
            res.v.push_back("+->" + s.v[i] + "->+");
        } else {
            res.v.push_back("|  " + s.v[i] + "  |");
        }
    }
    res.v.push_back("|  " + string(s.w(), ' ') + "  |");
    res.v.push_back("+<-" + string(s.w(), '-') + "--+");
    return res;
}

state parse_term(const string &s) {
    vector<pair<state, bool>> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            int bal = 1;
            const int start = i;
            ++i;
            while (bal) {
                if (s[i] == '(') {
                    ++bal;
                } else if (s[i] == ')') {
                    --bal;
                }
                ++i;
            }
            --i;
            v.push_back({parse_expr(s.substr(start + 1, i - 1 - (start + 1) + 1)), false});
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            state add;
            add.v.push_back({s[i]});
            v.push_back({add, true});
        } else {
            if (v.back().second) {
                v.back().second = false;
                v.back().first = only_letters(v.back().first.v[0]);
            }
            if (s[i] == '+') {
                v.back().first = apply_plus(v.back().first);
            } else if (s[i] == '?') {
                v.back().first = apply_question(v.back().first);
            } else if (s[i] == '*') {
                v.back().first = apply_star(v.back().first);
            } else {
                assert(false);
            }
        }
    }
    vector<state> all;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second) {
            string s;
            while (i < v.size() && v[i].second) {
                s += v[i].first.v[0];
                ++i;
            }
            --i;
            all.push_back(only_letters(s));
        } else {
            all.push_back(v[i].first);
        }
    }
    int h = 0;
    for (const state &s : all) {
        h = max(h, s.h());
    }
    state res;
    for (int i = 0; i < h; ++i) {
        string row;
        for (int j = 0; j < all.size(); ++j) {
            if (all[j].h() <= i) {
                row += string(all[j].w(), ' ');
            } else {
                row += all[j].v[i];
            }
            if (j + 1 < all.size()) {
                if (i == 1) {
                    row += "->";
                } else {
                    row += "  ";
                }
            }
        }
        res.v.push_back(row);
    }
    return res;
}

state parse_expr(const string &s) {
    vector<int> dels{-1};
    int bal = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|' && bal == 0) {
            dels.push_back(i);
        } else if (s[i] == '(') {
            ++bal;
        } else if (s[i] == ')') {
            --bal;
        }
    }
    dels.push_back(s.size());
    vector<state> terms;
    for (int i = 0; i + 1 < dels.size(); ++i) {
        terms.push_back(parse_term(s.substr(dels[i] + 1, dels[i + 1] - dels[i] - 1)));
    }
    if (terms.size() == 1) {
        return terms[0];
    }
    int w = 0;
    for (const auto &s : terms) {
        w = max(w, s.w());
    }
    w += 6;
    state res;
    res.v.clear();
    for (int i = 0; i < terms.size(); ++i) {
        for (int j = 0; j < terms[i].h(); ++j) {
            string add;
            if ((i == 0 && j == 0) || (i + 1 == terms.size() && j > 1)) {
                add += "   " + terms[i].v[j];
                while (add.size() < w) {
                    add += ' ';
                }
            } else {
                if (j == 1) {
                    add = "+->" + terms[i].v[j];
                    while (add.size() + 2 < w) {
                        add += '-';
                    }
                    add += ">+";
                } else {
                    add = "|  " + terms[i].v[j];
                    while (add.size() + 1 < w) {
                        add += ' ';
                    }
                    add += '|';
                }
            }
            res.v.push_back(add);
        }
        if (i + 1 < terms.size()) {
            string add(w, ' ');
            add[0] = add.back() = '|';
            res.v.push_back(add);
        }
    }
    return res;
}

state parse_input(const string &s) {
    state expr = parse_expr(s);
    state res;
    for (int i = 0; i < expr.h(); ++i) {
        if (i == 1) {
            res.v.push_back("S->" + expr.v[i] + "->F");
        } else {
            res.v.push_back("   " + expr.v[i] + "   ");
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    auto ans = parse_input(s);
    cout << ans << "\n";
    return 0;
}