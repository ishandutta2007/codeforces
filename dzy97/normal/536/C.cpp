#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 200010
struct line{
	int k, b;
	int id;
}p[N], st[N];
int n, ok[N];

bool cmp(const line &a, const line &b){
	if(a.k == b.k) return a.b > b.b;
	return a.k < b.k;
}
int top;

double cross(line p,line q){
	if(p.k == q.k)return 1e100;
	return double(q.b-p.b)/double(p.k-q.k);
}

void push(line x){
	while(top>1 &&1ll*(st[top-1].b*st[top].b-st[top-1].b*x.b)*(st[top].k*x.k-st[top-1].k*x.k)<1ll*(st[top-1].b*x.b-st[top].b*x.b)*(st[top-1].k*x.k-st[top-1].k*st[top].k))top--;
	st[++top]=x;
}
int main(){
	//freopen("data.in", "r", stdin);
	scanf("%d", &n);
	int x, y;
	for(int i = 1;i <= n;i ++){
		scanf("%d%d", &x, &y);
		p[i].k = x;
		p[i].b = y;
		p[i].id = i;
		//cout << p[i].k <<" "<< p[i].b << endl;
	}
	sort(p + 1, p + n + 1, cmp);
//	for(int i =1;i<=n;i++)

//	cout << p[i].k <<" "<< p[i].b << endl;
	push(p[1]);
	for(int i = 2;i <= n;i ++)
		if(p[i].k!=p[i-1].k) push(p[i]);
	for(int i=1;i<=top;i++) ok[st[i].id]=1;
	for(int i=1;i<top;i++)if(st[i].b<=st[i+1].b)ok[st[i].id]=0; else break;


	for(int i=2;i<=n;i++)
		if(p[i].k==p[i-1].k&&p[i].b==p[i-1].b)ok[p[i].id]|=ok[p[i-1].id];
	for(int i=1;i<=n;i++) 
		if(ok[i])printf("%d ",i);

	return 0;
}