#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

vector<int> ans;

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> w1, w2;

    for (int i = 1; i <= n; i++) if (i % 2 == 1) w1.pub(i); else w2.pub(i);

    if (w1.size() > w2.size()) swap(w1, w2);

	for (int x : w1) ans.pub(x);
	for (int x : w2) ans.pub(x);
	for (int x : w1) ans.pub(x);

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << ' ';
}