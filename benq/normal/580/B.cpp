#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair <int, int>

#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
int n,d,ind=-1;
ll cur,ans;
vector<pii> fr;

int main() {
	cin >> n >> d, fr.resize(n);
	F0R(i,n) cin >> fr[i].f >> fr[i].s;
	sort(fr.begin(),fr.end());
	F0R(i,n) {
		if (i > 0) cur -= fr[i-1].s;
		while (ind<n-1 && fr[ind+1].f-fr[i].f < d) ind++, cur += fr[ind].s;
		ans=max(cur,ans);
	}
	cout << ans;
}