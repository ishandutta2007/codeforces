#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
struct gg{
	int l1,r1,l2,r2;
	friend bool operator < (gg a,gg b){
		return a.r1>b.r1;
	}
}g[N];
int n;
bool cmp(gg a,gg b){return a.l1<b.l1;}
priority_queue<gg>Q1;
priority_queue<int>Q2,B2;
priority_queue<int,vector<int>,greater<int> >Q3,B3;
void del2(int x){
	B2.push(x);
	while(!B2.empty()&&B2.top()==Q2.top()){
		B2.pop();
		Q2.pop();
	}
}
void del3(int x){
	B3.push(x);
	while(!B3.empty()&&B3.top()==Q3.top()){
		B3.pop();
		Q3.pop();
	}
}
int top2(){return Q2.empty()?-INF:Q2.top();}
int top3(){return Q3.empty()?INF:Q3.top();}

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d%d%d",&g[i].l1,&g[i].r1,&g[i].l2,&g[i].r2);
	sort(g+1,g+n+1,cmp);
	rep(i,n){
		while(!Q1.empty()&&Q1.top().r1<g[i].l1){
			del2(Q1.top().l2);
			del3(Q1.top().r2);
			Q1.pop();
		}
		if(g[i].l2>top3()){
			puts("NO");
			return 0;
		}
		if(g[i].r2<top2()){
			puts("NO");
			return 0;
		}
		Q1.push(g[i]);
		Q2.push(g[i].l2);
		Q3.push(g[i].r2);
	}
	rep(i,n)swap(g[i].l1,g[i].l2),swap(g[i].r1,g[i].r2);
	while(!Q1.empty())Q1.pop();
	while(!Q2.empty())Q2.pop();
	while(!Q3.empty())Q3.pop();
	while(!B2.empty())B2.pop();
	while(!B3.empty())B3.pop();
	sort(g+1,g+n+1,cmp);
	rep(i,n){
		while(!Q1.empty()&&Q1.top().r1<g[i].l1){
			del2(Q1.top().l2);
			del3(Q1.top().r2);
			Q1.pop();
		}
		if(g[i].l2>top3()){
			puts("NO");
			return 0;
		}
		if(g[i].r2<top2()){
			puts("NO");
			return 0;
		}
		Q1.push(g[i]);
		Q2.push(g[i].l2);
		Q3.push(g[i].r2);
	}
	puts("YES");
	return 0;
}