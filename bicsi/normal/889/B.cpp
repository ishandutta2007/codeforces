#include <bits/stdc++.h>

using namespace std;

int GetMask(const string& str) {
    int ret = 0;
    for (auto& c : str) {
        if (ret & (1 << (c - 'a')))
            return -1;
        ret |= (1 << (c - 'a'));
    }
    return ret;
}

vector<string> Combine(vector<string> old, string with) {
    vector<string> ret;
//    cerr << with << endl;

    for (auto oth : old) {
//        cerr << "ck " << oth << endl;
        // Check inside
        if (with.find(oth) != string::npos) {
            continue;
        }

        if (oth.find(with) != string::npos) {
            with = oth;
            continue;
        }

        auto it = find(oth.begin(), oth.end(), with[0]);
        if (it != oth.end()) {
//            cerr << "CASE 1" << endl;

            auto it2 = with.begin();

            while (it != oth.end()) {
                if (*it != *it2) {
                    cout << "NO" << endl;
                    exit(0);
                }           
                ++it, ++it2;     
            }

            while (it2 != with.end()) {
                oth += *it2;
                ++it2;
            }
            with = oth;
            continue;
        }

        it = find(oth.begin(), oth.end(), with.back());
        if (it != oth.end()) {
//            cerr << "CASE 2" << endl;

            auto it2 = with.end();
            --it2;

            while (true) {
                if (*it != *it2) {
                    cout << "NO" << endl;
                    exit(0);
                }
                if (it == oth.begin()) break;
                --it, --it2;
            }
            
            while (true) {
                if (it2 == with.begin()) break;
                --it2;
                oth = string() + (*it2) + oth;
            }
            with = oth;
            continue;
        }

        ret.push_back(oth);
    }
    ret.push_back(with);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    vector<string> strs(n);
    vector<int> msks(n);

    for (int i = 0; i < n; ++i) {
        cin >> strs[i];

        if (GetMask(strs[i]) == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<string> pruned;
    for (int i = 0; i < n; ++i) {
        pruned = Combine(pruned, strs[i]);
    }
    
    sort(pruned.begin(), pruned.end());
    string ret = "";
    for (auto x : pruned) ret += x;
    if (GetMask(ret) == -1) {
        cout << "NO" << endl;
    } else {
        cout << ret << endl;
    }

    return 0;
}