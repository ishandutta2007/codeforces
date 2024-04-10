#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = 1e9;
char g[105][105];
int d[105][105],r,c;

queue<pii> Q;
int ud = 2,lr = 2;


void try_add(int i, int j, int p) {
	if(i < 0 || j < 0 || i >= r || j >= c) return;
	if(g[i][j] == '*') return;
	if(d[i][j] != INF) return;
	d[i][j] = p;
	Q.push(pii(i,j));
}

int val(int i, int j) {
	if(i < 0 || j < 0 || i >= r || j >= c) return INF;
	return d[i][j];
}

pii get_move(int i, int j) {
	if(val(i+1,j) < val(i,j)) return pii(i+1,j);
	if(val(i-1,j) < val(i,j)) return pii(i-1,j);
	if(val(i,j+1) < val(i,j)) return pii(i,j+1);
	if(val(i,j-1) < val(i,j)) return pii(i,j-1);
	return pii(-1,-1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d %d",&r,&c);
	int fi,fj;
	for(int i = 0; i < r; ++i) {
		scanf("%s",g[i]);
		for(int j = 0; j < c; ++j) {
			if(g[i][j] == 'F') {
				fi = i;
				fj = j;
			}
			d[i][j] = INF;
		}
	}
	try_add(fi,fj,0);
	while(!Q.empty()) {
		pii p = Q.front();
		Q.pop();
		int i=p.first,j=p.second;
		int w = 1+d[i][j];
		try_add(i+1,j,w);
		try_add(i-1,j,w);
		try_add(i,j+1,w);
		try_add(i,j-1,w);
	}
	int i=0,j=0,x,y;
	while(d[i][j] != 0) {
		pii p = get_move(i,j);
		if(i != p.first) {
			if(ud == 2) {
				printf("D\n");
				fflush(stdout);
				scanf("%d %d",&x,&y); --x; --y;
				if(x == i) ud = 1;
				else ud = 0;
			} else {
				if(ud != p.first < i) printf("U\n");
				else printf("D\n");
				fflush(stdout);
				scanf("%d %d",&x,&y); --x; --y;
			}
			i = x;
		} else if(j != p.second) {
			if(lr == 2) {
				printf("R\n");
				fflush(stdout);
				scanf("%d %d",&x,&y); --x; --y;
				if(y == j) lr = 1;
				else lr = 0;
			} else {
				// printf("%d %d",lr,p.second<j);
				if(lr != p.second < j) printf("L\n");
				else printf("R\n");
				fflush(stdout);
				scanf("%d %d",&x,&y); --x; --y;
			}
			j = y;
		}
	}



	return 0;
}