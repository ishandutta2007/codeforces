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

/*
char missing(int a[26], b[26]) {
    for (int i=0; i<26; ++i) {
        assert(b[i] <= a[i]);
        if (b[i] < a[i]) return (char)(i+'a');
    }
    return '?';
}
*/
char rem(int a[26]) {
    char res = '?';
    int amt = 0;
    for (int i=0; i<26; ++i) {
        amt += a[i];
        if (a[i]) res = ('a' + i);
    }
    //cerr << "AMT = " << amt << endl;
    assert(amt == 1);
    return res;
}

void obtain(int l, int r, int x) {
    cout << "? " << l << " " << r << endl;
    int k = (r-l+1);

    for (int i=0; i<k*(k+1)/2; ++i) {
        string a;
        cin >> a;
        for (auto& c : a) {
            s[x][i][c-'a']++;
        }
        mp[x][hsh(s[x][i])]++;
        //cerr << " -- " << a << " :: " << hsh(s[x][i]) << " " << mp[x][hsh(s[x][i])]<< endl;
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

    obtain(1, n, 0);
    obtain(1, n-1, 1);
    /*
    int rt = 0;
    for (int i=0; i<sz[0]; ++i) {
        if (bs[0][i] == n) {
            rt = i;
        }
    }
    for (int i=0; i<sz[1]; ++i) {
        if (bs[1][i] == n-1) {
            ans[n] = missing(s[0][rt], s[1][i]);
        }
    } */

    int nd[110];
    memset(nd, 0, sizeof nd);

    for (int i=0; i<sz[0]; ++i) {
        int h = hsh(s[0][i]);
        if (!mp[1].count(h) || mp[0][h] > mp[1][h]) {
            int zz = bs[0][i];
            nd[n+1-zz] = i;
            //cerr << " FOR POS " << n+1-zz << " SET " << i << " WITH " << zz << endl;
        }
    }

    for (int i=n; i; --i) {
        //cerr << " :: " << i << " :: " << nd[i] << endl;
        int tmp[26];
        ////cerr <<" :: " << i << endl;
        for (int j=0; j<26; ++j) {
            tmp[j] = s[0][nd[i]][j];
            ////cerr << " ," << tmp[j];
        }
        ////cerr << endl;
        for (int j=i+1; j<=n; ++j) {
            tmp[ans[j]-'a']--;
        }
        ans[i] = rem(tmp);
    }
    cout << "! "<< (ans+1) << endl;

    

    return 0;
}