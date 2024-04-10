// writer: piggydan
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
#define int ll
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

bool siv[1000006];
int ooc[1000006], ocu[1000006];
vector<int> pos[1000006], pr;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, M; cin >> N >> M;
    rep(i, N) {
        int v; cin >> v;
        if(v <= M) { ooc[v]++; pos[v].push_back(i+1); }
    }
    siv[1] = 1;
    iter(i, 1, M+1) {
        if(!siv[i]) {
            pr.push_back(i);
            for(int j=i*i; j<=M; j+=i) siv[j]=1; 
        }
        if(ooc[i]) for(int j=i; j<=M; j+=i) ocu[j] += ooc[i];
    }
    int bes = 1;
    rep(i, M+1) if(ocu[i] > ocu[bes]) bes = i;
    cout << bes << ' ' << ocu[bes] << endl;
    vector<int> ans;
    iter(i, 1, M+1) {
        if(bes%i) continue;
        for(int j:pos[i]) ans.push_back(j);
    }
    sort(all(ans));
    for(int i:ans) cout << i << ' ';
    cout << endl;
}