#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int n;

const int Q = 11111;

int s[6][Q][26];
unordered_map<int, int> mp[6];
int sz[6];
int bs[6][Q];
char ans[110];
int cnt[110][26];

const ll PRI = 8381;
const ll MOD = 92928593;

ll pro[30];
void setup() {
    ll b = 1;
    for (int i=0; i<30; ++i) {
        pro[i] = b;
        b = b*PRI%MOD;
    }
}

int hsh(int q[26]) {
    ll ans = 0;
    for (int i=0; i<26; ++i) {
        ans += pro[i]*q[i];
    }
    return ans%MOD;
}

char rem(int a[26]) {
    char res = '?';
    int amt = 0;
    for (int i=0; i<26; ++i) {
        amt += a[i];
        if (a[i]) res = ('a' + i);
    }
    //cerr << " REM " << amt << endl;
    assert(amt == 1);
    return res;
}

void obtain(int l, int r, int x) {
    if (l > r) return;
    cout << "? " << l << " " << r << endl;
    int k = (r-l+1);

    for (int i=0; i<k*(k+1)/2; ++i) {
        string a;
        cin >> a;
        for (auto& c : a) {
            s[x][i][c-'a']++;
        }
        mp[x][hsh(s[x][i])]++;
        bs[x][i] = a.size();
    }

    sz[x] = k*(k+1)/2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    if (n <= 3) {
        string t;
        for (int i=1; i<=n; ++i) {
            cout << "? " << i << " " << i << endl;
            string c;
            cin >> c;
            t += c;
        }
        cout << "! " << t << endl;
        return 0;
    }

    int m = n/2;

    obtain(1, m, 0);
    obtain(1, m-1, 1);
    obtain(1, n, 2);

    int nd[110];
    memset(nd, 0, sizeof nd);

    for (int i=0; i<sz[0]; ++i) {
        int h = hsh(s[0][i]);
        if (!mp[1].count(h) || mp[0][h] > mp[1][h]) {
            int zz = bs[0][i];
            nd[m+1-zz] = i;
            //cerr << " FOR " << m+1-zz << " " << i << endl;
        }
    }

    for (int i=m; i; --i) {
        int tmp[26];
        for (int j=0; j<26; ++j) {
            tmp[j] = s[0][nd[i]][j];
        }
        for (int j=i+1; j<=m; ++j) {
            tmp[ans[j]-'a']--;
        }
        ans[i] = rem(tmp);
    }

    for (int i=0; i<sz[2]; ++i) {
        for (int j=0; j<26; ++j) {
            cnt[bs[2][i]][j] += s[2][i][j];
        }
    }

    for (int i=(n+1)/2; i; --i) {
        int tmp[26];
        memset(tmp, 0, sizeof tmp);
        for (int j=0; j<26; ++j) {
            tmp[j] = cnt[i][j] - cnt[i-1][j];
            //cerr << "  : " << tmp[j] << endl;
        }
        // how many between [i,n+1-i] ?
        //cerr << " ??? " << i << " " << n+1-i << endl;
        for (int j=i; j<n-i+1; ++j) {
            tmp[ans[j]-'a']--;
            //cerr << " REM " << ans[j] << endl;
        }
        char th = 0;
        for (int j=0; j<26; ++j) {
            if (tmp[j]) {
                assert(tmp[j] == 1);
                //cerr << " WAS ALREADY " << th << " WANT " << (char)(j+'a') << endl;
                assert(th == 0);
                th = j+'a';
            }
        }
        assert(th);
        ans[n-i+1] = th;
        //cerr << "ASSIGN " << n+i-1 << endl;
    }

    
    cout << "! " << (ans+1) << endl;

    return 0;
}