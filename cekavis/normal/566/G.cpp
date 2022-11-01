#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, m;
struct item{
	int x, y;
	bool operator<(const item &r)const{ return x==r.x?y>r.y:x<r.x;}
	item operator-(const item &r)const{ return (item){x-r.x, y-r.y};}
	ll operator*(const item &r)const{ return (ll)x*r.y-(ll)y*r.x;}
} a[N], b[N];
int main() {
	scanf("%d%d%*d%*d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	for(int i=1; i<=m; ++i) scanf("%d%d", &b[i].x, &b[i].y);
	sort(a+1, a+n+1), sort(b+1, b+m+1);
	int top=1;
	for(int i=2; i<=m; ++i){
		while(top && b[i].y>b[top].y) --top;
		while(top>1 && (b[i]-b[top])*(b[top]-b[top-1])<0) --top;
		b[++top]=b[i];
	}
	for(int i=1, x=1; i<=n; ++i){
		while(x<=m && b[x].x<=a[i].x) ++x;
		// printf(">> %d\n", x);
		if(x>m || (b[x].y<=a[i].y && (x==1 || (b[x]-a[i])*(a[i]-b[x-1])>=0)))
			return puts("Max"), 0;
	}
	puts("Min");
	return 0;
}