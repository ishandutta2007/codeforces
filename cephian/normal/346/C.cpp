#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

unordered_set<int> xs;
vi x,t;
int a,b,n;

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int X;
		scanf("%d",&X);
		if(xs.count(X)) continue;
		xs.insert(X);
		x.pb(X);
	}
	scanf("%d%d",&a,&b);
	int ans = 0;
	while(a > b) {
		int nxt = a-1;
		t.clear();
		for(int X : x) {
			int c = a/X*X;
			if(c >= b) {
				t.pb(X);
				nxt = min(nxt,c);
			}
		}
		swap(x,t);
		a = nxt;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}