#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi T;

pii find_tris(int a, int b) {
	int w[2]={-1,-1},sz=0;
	for(int x : T[a]) {
		for(int y : T[b]) {
			if(x == y) {
				w[sz++] = y;
				break;
			}
		}
	}
	return pii(w[0],w[1]);
}

bool uneq(int a, int b, int c) {
	pii p = find_tris(a,b);
	if(p.fi != -1 && p.fi != c) return true;
	return p.se != -1 && p.se != c;
}

void reorder(int &a, int &b, int &c) {
	bool ab = uneq(a,b,c);
	bool ac = uneq(a,c,b);
	bool bc = uneq(b,c,a);
	if(ab && bc) return;
	else if(ab && ac) swap(b,a);
	else if(bc && ac) swap(b,c);
}


vector<int> ans;
set<pii> edges;
set<pii> ed2;

int main() {
	int n;
	scanf("%d",&n);
	if(n == 5) {
		printf("1 2 3 4 5\n");
		return 0;
	}
	T = vvi(n);
	for(int i = 0; i < 2*n; ++i) {
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		T[a].pb(b), T[b].pb(a);
		edges.insert(pii(min(a,b),max(a,b)));
	}
	if(T[0].size() == 4) {	
		int a = 0, b = T[0][0], c = find_tris(a,b).first;
		if(c != -1) {
			reorder(a,b,c);
			ans.pb(a), ans.pb(b), ans.pb(c);
			while(ans.size() != n) {
				a = ans[ans.size()-3], b = ans[ans.size()-2], c = ans[ans.size()-1];
				pii p  = find_tris(b,c);
				int d = (p.fi == a)?p.se:p.fi;
				if(d == -1)
					break;
				ans.pb(d);
			}
		}
	}
	//check
	for(int i = 0; i < ans.size(); ++i) {
		int j = (i+1) % n;
		int k = (i+2) % n;
		ed2.insert(pii(min(ans[i],ans[j]),max(ans[i],ans[j])));
		ed2.insert(pii(min(ans[i],ans[k]),max(ans[i],ans[k])));
	}
	if(edges != ed2) {
		printf("-1\n");
		return 0;
	}

	for(int k : ans) {
		printf("%d ",k+1);
	}
	printf("\n");
}