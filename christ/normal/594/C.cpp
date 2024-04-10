#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define unq(x) sort(all(x)); (x).erase(unique(all(x)),(x).end())
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
struct Point {
	int x,y,id;
	bool operator< (const Point &o) const {
		return mp(x,mp(y,id)) < mp(o.x,mp(o.y,o.id));
	}
} xsrt[MN], ysrt[MN];
int main () {
	int n,k;
	scanf ("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		int x,y,x2,y2;
		scanf ("%d %d %d %d",&x,&y,&x2,&y2);
		xsrt[i] = ysrt[i] = {x+x2,y+y2,i};
	}
	sort(xsrt+1,xsrt+1+n);
	sort(ysrt+1,ysrt+1+n,[](const Point &a, const Point &b){return a.y < b.y;});
	vector<int> boundl, boundr, boundu, boundd;
	for (int i = 1; i <= k+1; i++) boundl.push_back(xsrt[i].x), boundr.push_back(xsrt[n-i+1].x), boundu.push_back(ysrt[i].y), boundd.push_back(ysrt[n-i+1].y);
	unq(boundl); unq(boundr); unq(boundu); unq(boundd);
	ll ans = 5e18;
	for (int l : boundl) {
		for (int r : boundr) if (l <= r) {
			for (int u : boundu) {
				for (int d : boundd) if (u <= d) {
					set<Point> out;
					for (int i = 1; i <= n; i++) {
						if (xsrt[i].x < l) out.insert(xsrt[i]);
						else break;
					} 
					for (int i = 1; i <= n; i++) {
						if (ysrt[i].y < u) out.insert(ysrt[i]);
						else break;
					}
					for (int i = n; i >= 1; i--) {
						if (xsrt[i].x > r) out.insert(xsrt[i]);
						else break;
					}
					for (int i = n; i >= 1; i--) {
						if (ysrt[i].y > d) out.insert(ysrt[i]);
						else break;
					}
					if ((int)out.size() > k) continue;
					ans = min(ans,max((r-l+1)/2,1) * 1LL * max((d-u+1)/2,1));
				}
			}
		}
	} 
	printf ("%lld\n",max(ans,1LL));
    return 0;
}