#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e5+5, MM = 1e6+3;
vector<int> bs;
struct Lady {
	int a,b,c;
} ladies[MN];
int bit[MN];
int n;
void update (int i, int v) {
	for (i=MN-i;i<MN;i+=i&-i)
		bit[i] = max(bit[i],v);
}
int query (int i) {
	int ret = 0;
	for(i=MN-i;i;i^=i&-i)
		ret = max(ret,bit[i]);
	return ret;
}
void getb (int &b) {b = lower_bound(all(bs),b)-bs.begin()+1;}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&ladies[i].a);
	for (int i = 1; i <= n; i++) scanf ("%d",&ladies[i].b), bs.push_back(ladies[i].b);
	for (int i = 1; i <= n; i++) scanf ("%d",&ladies[i].c);
	sort(all(bs));
	for (Lady &l : ladies) getb(l.b);
	sort(ladies+1,ladies+1+n,[](Lady a, Lady b){return a.a > b.a;});
	vector<Lady> toadd; int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ladies[i].a != ladies[i-1].a) {
			for (Lady &l : toadd) update(l.b,l.c);
			toadd.clear();
		}
		toadd.push_back(ladies[i]);
		ans += query(ladies[i].b+1) > ladies[i].c;
	}
	printf ("%d\n",ans);
	return 0;
}