#include <bits/stdc++.h>
using namespace std;

bool ask(vector<int> a) {
    cout << "? " << a.size() << " ";
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    string res;
    cin >> res;
    return res == "YES" ? 1 : 0;
}

bool guess(int val) {
    cout << "! " << val << endl;
    string res;
    cin >> res;
    return res == ":)" ? 1 : 0;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> values;
    for (int i = 1; i<=n; ++i) {
        values.push_back(i);
    }
    
    while (values.size()) {
        if (values.size() == 1) {
            assert(guess(values[0]));
            exit(0);
        } else if (values.size() == 2) {
            if (guess(values[0])) {
                exit(0);
            } else {
                assert(guess(values[1]));
                exit(0);
            }
        } else if (values.size() == 3) {
            bool a = ask({values[0]});
            if (a) {
                if (guess(values[0])) {
                    exit(0);
                } else {
                    if (ask({values[1]})) {
                        guess(values[1]);
                    } else {
                        guess(values[2]);
                    }
                    exit(0);
                }
            } else {
                if (ask({values[1], values[2]})) {
                    if (guess(values[1])) {
                        exit(0);
                    } else {
                        assert(guess(values[2]));
                        exit(0);
                    }
                } else {
                    if (guess(values[0])) {
                        exit(0);
                    } else {
                        if (ask({values[1]})) {
                            guess(values[1]);
                        } else {
                            guess(values[2]);
                        }
                        exit(0);
                    }
                }
            }
        } else {
            vector<int> a, b, c, d;
            int m = values.size();
            int s1 = m/4, s2 = (m-s1)/3, s3 = (m-s1-s2)/2, s4 = m-s1-s2-s3;
            for (int i = 0; i<s1; ++i) {
                a.push_back(values[i]);
            }
            for (int i = 0; i<s2; ++i) {
                b.push_back(values[s1+i]);
            }
            for (int i = 0; i<s3; ++i) {
                c.push_back(values[s1+s2+i]);
            }
            for (int i = 0; i<s4; ++i) {
                d.push_back(values[s1+s2+s3+i]);
            }
            vector<int> ask1 = a;
            ask1.insert(ask1.end(), b.begin(), b.end());
            vector<int> ask2 = b;
            ask2.insert(ask2.end(), c.begin(), c.end());
            bool res1 = ask(ask1);
            bool res2 = ask(ask2);
            vector<int> new_vals;
            if (!res1) {
                new_vals = c;
                new_vals.insert(new_vals.end(), d.begin(), d.end());
                if (res2) {
                    new_vals.insert(new_vals.end(), b.begin(), b.end());
                } else {
                    new_vals.insert(new_vals.end(), a.begin(), a.end());
                }
            } else {
                new_vals = a;
                new_vals.insert(new_vals.end(), b.begin(), b.end());
                if (res2) {
                    new_vals.insert(new_vals.end(), c.begin(), c.end());
                } else {
                    new_vals.insert(new_vals.end(), d.begin(), d.end());
                }
            }
            swap(values, new_vals);
        }
    }
}