#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//#define int ll

vector<string> ve;

bool cmp(const string a, const string b) {
    return (a+b < b+a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
    rep(i, n) {
        string s; cin >> s;
        ve.push_back(s);
    }
    sort(all(ve), cmp);
    rep(i, n) {
        cout << ve[i];
    }
    cout << endl;
}