#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk
#define endl '\n'

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

vector<string> refs;
vector<string> biba;
map<string, string> desc;

bool read() {
    return true;
}

void solve() {
    string s;
    bool b = false;
    while (getline(cin, s)) {
        if (!b) {
            if (s == "\\begin{thebibliography}{99}") {
                b = true;
            } else {
                while(true)
                {
                    int k = s.find("\\cite{");
                    if(k == -1)
                        break;
                    string nm = "";
                    for(int z = k + 6; z < sz(s); z++)
                    {
                        if(s[z] == '}')
                        {
                            s[k] = 'w';
                            break;
                        } else
                            nm.pb(s[z]);
                    }
                    refs.pb(nm);
                }
            }
        } else if(s.substr(0, 9) == "\\bibitem{"){
            string nm = "";
            int pos = -1;
            for (int i = 9; i < sz(s); i++) {
                if (s[i] == '}') {
                    pos = i;
                    break;
                } else
                    nm.pb(s[i]);
            }
            pos++;
            string w = s.substr(pos, INF);
            desc[nm] = w;
            biba.pb(nm);
        }
    }
    if (biba == refs)
        cout << "Correct" << endl;
    else
    {
        cout << "Incorrect" << endl;
        cout << "\\begin{thebibliography}{99}" << endl;
        for(auto x : refs)
            cout << "\\bibitem{" << x << "}" << desc[x] << endl;
        cout << "\\end{thebibliography}" << endl;
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}