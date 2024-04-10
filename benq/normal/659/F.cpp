#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pii pair <int, int>
#define vi vector<int>
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define f first
#define s second

ll numcomp = 0, cur, n,m,num,k;
ll g[1000][1000], v[1000][1000], ans[1000][1000];
set<pii> u;

void ff(int c, int d) {
	if(c<0 || d<0 || c>=m || d>=n || g[c][d]<cur || v[c][d])return;
	if (g[c][d] == cur) u.insert(mp(c,d));
	v[c][d] = 1;
	num++;
	ff(c+1,d), ff(c-1,d), ff(c,d+1), ff(c,d-1);
}

void ff2(int c, int d) {
	if(num>=k/cur || c<0 || d<0 || c>=m || d>=n || !v[c][d] || ans[c][d])return;
	ans[c][d] = cur;
	num++;
	ff2(c+1,d), ff2(c-1,d), ff2(c,d+1), ff2(c,d-1);
}

int main() {
	cin >> n >> m >> k;
	F0R(i,n) F0R(j,m) scanf("%d",&g[j][i]);
	F0R(i,n) F0R(j,m) {
		cur = g[j][i];
		if (k/cur>n*m || k % cur != 0 || u.find({j,i}) != u.end()) continue;
		memset(v,0,sizeof(v));
		num = 0;
		ff(j,i);
		if(num >= k/cur) {
                num=0;
                memset(ans,0,sizeof(ans));
                ff2(j,i);
                printf("YES\n");
                F0R(i,n) {
                	F0R(j,m) printf("%d ",ans[j][i]);
                    printf("\n");
                }
                return 0;
            }
	}
	
	cout << "NO" << endl;
	return 0;
}