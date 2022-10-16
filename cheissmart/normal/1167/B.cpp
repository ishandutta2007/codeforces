#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int ok[100];

int main()
{
	
	int a[10], ans[10];
	vi v, vv;
	for(int i=1;i<=4;i++) {
		cout << "? " << i << " " << i + 1 << endl;
		cin >> a[i];
		if(a[i] % 23 == 0)
			v.PB(i);
		if(a[i] % 15 == 0)
			vv.PB(i);
	}
	int p, x = 23;
	if(v.size() == 1) {
		if(v[0] == 1) p = 1;
		else p = 5;
	} else if (v.size() == 2) {
		p = v[1];
	} else {
		x = 15;
		if(vv.size() == 1) {
			if(vv[0] == 1) p = 1;
			else p = 5;
		} else if (vv.size() == 2) {
			p = vv[1];
		} 
	}
	ans[p] = x;
	for(int i=p+1;i<=5;i++)
		ans[i] = a[i-1] / ans[i-1];
	for(int i=p-1;i>=1;i--)
		ans[i] = a[i] / ans[i+1];
	for(int i=1;i<=5;i++)
		ok[ans[i]] = 1;
	vi vvv({4 , 8, 15, 16, 23, 42});
	for(int e:vvv)
		if(!ok[e])
			ans[6] = e;
	cout << "! ";
	for(int i=1;i<=6;i++)
		cout << ans[i] << ' ';
	cout << endl;
}