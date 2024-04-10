#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
#define y1 ____aksakjy1

const int N = 1e5+5;
int u[N],d[N],l[N],r[N];
int x1[N],y1[N],x2[N],y2[N];
int w,n,m;

int lt(int* L, int v, int m) {
	int lo = -1, hi = w;
	while(hi-lo>1) {
		int md = (lo+hi)/2;
		if(L[md]*m < v*m) lo = md;
		else hi = md;
	}
	return lo+1;
}

int main() {
	scanf("%d%d%d",&w,&n,&m);

	for(int i = 0; i < w; ++i) {
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		l[i] = min(x1[i],x2[i]);
		r[i] = max(x1[i],x2[i]);
		u[i] = min(y1[i],y2[i]);
		d[i] = max(y1[i],y2[i]);
	}
	sort(l,l+w);
	sort(r,r+w);
	sort(u,u+w);
	sort(d,d+w);
	reverse(r,r+w);
	reverse(d,d+w);
	int L,R,U,D;
	scanf("%d%d%d%d",&L,&R,&U,&D);
	for(int i = 0; i < w; ++i) {
		if(L+(y1[i]==y2[i]) != lt(l,max(x1[i],x2[i]),1)) continue;
		if(R+(y1[i]==y2[i]) != lt(r,min(x1[i],x2[i]),-1)) continue;		
		if(U+(x1[i]==x2[i]) != lt(u,max(y1[i],y2[i]),1)) continue;
		if(D+(x1[i]==x2[i]) != lt(d,min(y1[i],y2[i]),-1)) continue;
		printf("%d\n",i+1);
		return 0;
	}
	printf("-1\n");
}