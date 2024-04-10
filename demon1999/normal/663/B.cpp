
 #include <bits/stdc++.h>


#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
#define prev previouss
using namespace std;


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

ll k1, k2, n;
unordered_map<string, int> pp;
string pq[100000];
string s;
char p[20];

void my_assert(bool ok) {
    if (!ok) while(true);
}
signed main(){
    //iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("division.in", "r",  stdin));
    scanf("%d", &n);
    for (int i = 1989; i <= 500000; i++) {
        string s = "", t = "";
        int k = i;
        while (k) {
            t = "";
            t += char(k % 10 + '0');
            t += s;
            s = t;
            k /= 10;
            if (pp[s] == 0) {
                if (i < 100000) {
                    pq[i] = s;
                }
                pp[s] = i;
                break;
            }
        }
    }
    //re 0;
    forn (i, n) {
        scanf("%s", p);
        s = p;
        s.erase(s.begin(), s.begin() + 4);
        //cout << s << endl;
        if (sz(s) >= 6) {
            bool ok = true;
            for (int i = 0; i < sz(s); i++) {
                if (i + 4 == sz(s)) {
                    int k = (((s[i] - '0') * 10 + s[i + 1] - '0') * 10 + s[i + 2] - '0') * 10 + s[i + 3] - '0';
                    my_assert(k < 100000);
                    if (k >= 1989 && sz(pq[k]) == 4) ok = false;
                    break;
                }
                if (s[i] == '1') continue;
                if (s[i] == '0') break;
                ok = false;
            }
            if (ok) cout << "1";
            cout << s << "\n";
            continue;
        }
        cout << pp[s] << "\n";
    }
    return 0;
}