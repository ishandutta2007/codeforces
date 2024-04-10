#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MN = 1e5+3, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
struct Shape {
	int x,y,z,ind;
	void read (int i) {ind=i;scanf ("%d%d%d",&x,&y,&z);}
};
int main () {
    int n;
	scanf ("%d",&n);
	vector<Shape> a(n);
	for (int i = 0; i < n; i++) a[i].read(i+1);
	sort(all(a),[](Shape aa, Shape b){return aa.x<b.x||(aa.x==b.x&&aa.y<b.y)||(aa.x==b.x&&aa.y==b.y&&aa.z<b.z);});
	vector<Shape> b;
	for (int i = 0; i < n; i++) {
		if (i != n-1 && a[i].x==a[i+1].x&&a[i].y==a[i+1].y) {
			printf ("%d %d\n",a[i].ind,a[i+1].ind);
			++i;
		} else {
			b.push_back(a[i]);
		}
	}
	n = b.size();
	vector<Shape> c;
	for (int i = 0; i < n; i++) {
		if (i != n-1 && b[i].x == b[i+1].x) {
			printf ("%d %d\n",b[i].ind,b[i+1].ind);
			++i;
		} else {
			c.push_back(b[i]);
		}
	}
	n = c.size();
	for (int i = 0; i < n; i += 2) {
		printf ("%d %d\n",c[i].ind,c[i+1].ind);
	}
    return 0;
}