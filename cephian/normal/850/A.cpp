#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
int n;
struct pt {
	int a,b,c,d,e;
	
};

pt p[1005];
vi g;

int main() {	
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d%d%d%d",&p[i].a,&p[i].b,&p[i].c,&p[i].d,&p[i].e);
	for(int i = 0; i < n; ++i) {
		bool good = true;
		for(int j = 0; good && j < min(n,25); ++j) {
			if(j==i) continue;
			for(int k = j+1; good && k < min(n,25); ++k) {
				if(k == i || k == j) continue;
				int d = 0;
				d += (p[j].a-p[i].a) * (p[k].a-p[i].a);
				d += (p[j].b-p[i].b) * (p[k].b-p[i].b);
				d += (p[j].c-p[i].c) * (p[k].c-p[i].c);
				d += (p[j].d-p[i].d) * (p[k].d-p[i].d);
				d += (p[j].e-p[i].e) * (p[k].e-p[i].e);
				if(d > 0) {
					good = false;
				}
			}
		}
		if(good)
			g.pb(i+1);
	}
	printf("%d\n",int(g.size()));
	for(int a : g)
		printf("%d\n",a);
}