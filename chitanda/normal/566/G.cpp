#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
struct point{
	int x, y;
	point() {}
	point(int x, int y) : x(x), y(y) { }
	bool operator < (const point &o) const{
		return x < o.x || (x == o.x && y > o.y);
	}
	point operator - (const point &o) const{
		return point(x - o.x, y - o.y);
	}
}p[maxn], q[maxn];
ll cross(point a, point b){
	return (ll)a.x * b.y - (ll)a.y * b.x;
}
ll cross(point a, point b, point c){
	return cross(b - a, c - a);
}

int n, m;
int sta1[maxn], sta2[maxn];
int top1, top2;

void work(int n, point p[], int sta[], int &top){
	for(int i = 1; i <= n; ++i){
		while((top > 1 && cross(p[sta[top - 1]], p[sta[top]], p[i]) >= 0) || (top == 1 && p[sta[top]].y <= p[i].y)) --top;
		sta[++top] = i;
	}
	sta[++top] = n + 1;
	p[0] = point(0, p[sta[1]].y);
	p[n + 1] = point(p[sta[top - 1]].x, 0);
}

int main(){
	scanf("%d%d", &n, &m);
	int xx, yy;
	scanf("%d%d", &xx, &yy);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &q[i].x, &q[i].y);
	}
	sort(p + 1, p + n + 1);
	sort(q + 1, q + m + 1);
	work(n, p, sta1, top1);	
	work(m, q, sta2, top2);
	
	bool flag = 1;
	for(int i = 1, j = 1; i <= top1; ++i){
		while(cross(point(0, 0), q[sta2[j]], p[sta1[i]]) < 0) ++j;
		if(cross(q[sta2[j - 1]], q[sta2[j]], p[sta1[i]]) >= 0) flag = 0;
	}
	printf("%s\n", flag ? "Min" : "Max");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}