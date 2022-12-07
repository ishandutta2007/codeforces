#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

const int xx[] = {0, 0, 1, -1};
const int yy[] = {1, -1, 0, 0};

char fix[] = {'<', '>', '^', 'v'};

int n, m;
char mp[2010][2010];
bool flag;

inline int ok(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m && mp[x][y] == '.';
}

inline bool only(int x, int y){
	if(mp[x][y] != '.') return 0;
	int tmp = 0;
	for(int i = 0; i < 4; ++i)
		tmp += ok(x + xx[i], y + yy[i]);
	if(tmp == 1) return 1;
	else{
		if(!tmp) flag = 0;	 
		return 0;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", mp[i]);
	queue<pii> q;
	bool flag = 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(only(i, j))
				q.push(mkp(i, j));
	while(!q.empty()){
		int x = q.front().fi, y = q.front().se; q.pop();
		if(!ok(x, y)) continue;
		for(int i = 0; i < 4; ++i)
			if(ok(x + xx[i], y + yy[i])){
				mp[x][y] = fix[i], mp[x + xx[i]][y + yy[i]] = fix[i ^ 1];
				for(int j = 0; j < 4; ++j){
					if(only(x + xx[j], y + yy[j]))
						q.push(mkp(x + xx[j], y + yy[j]));
					if(only(x + xx[i] + xx[j], y + yy[i] + yy[j]))
						q.push(mkp(x + xx[i] + xx[j], y + yy[i] + yy[j]));
				}
				break;
			}
	}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(mp[i][j] == '.') flag = 0;
	if(!flag) puts("Not unique");
	else{
		for(int i = 0; i < n; ++i)
			puts(mp[i]);
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}