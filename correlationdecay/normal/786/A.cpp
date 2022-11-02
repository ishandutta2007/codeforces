#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#define maxn 7009
using namespace std;
int n;
vector<int>s1,s2;
bool lose[maxn],win[maxn];
int cnt[maxn];
int ans[maxn];
void solve(vector<int>& s1, vector<int>& s2){
	queue<int>Q, q;
	int n1 = s1.size();
	int n2 = s2.size();
	memset(ans, 0, sizeof(ans));
	memset(win, 0, sizeof(win));
	memset(lose, 0, sizeof(lose));
	memset(cnt, 0, sizeof(cnt));
	lose[0] = 1;
	Q.push(0);
	while(!Q.empty()){
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			for(int i = 0; i < n1; i++){
				int v = (u - s1[i] + n) % n;
				if(win[v] == 0 && v != 0){
					win[v] = 1;
					q.push(v);
				}
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0 ; i < n2; i++){
				int v = (u - s2[i] + n) % n;
				cnt[v]++;
				if(cnt[v] == n2 && lose[v] == 0){
					lose[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(win[i])
			ans[i] = 1;
	}
	
	memset(win, 0, sizeof(win));
	memset(lose, 0, sizeof(lose));
	memset(cnt, 0, sizeof(cnt));
	lose[0] = 1;
	q.push(0);
	while(!q.empty()){
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0 ; i < n2; i++){
				int v = (u - s2[i] + n) % n;
				if(win[v] == 0 && v != 0){
					win[v] = 1;
					Q.push(v);
				}
			}
		}
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			for(int i = 0; i < n1; i++){
				int v = (u - s1[i] + n) % n;
				cnt[v]++;
				if(cnt[v] == n1 && lose[v] == 0){
					lose[v] = 1;
					q.push(v);
				}
			}
		}
	}
	for(int i = 0 ; i < n; i++){
		if(lose[i])
			ans[i] = 2;
	}
	
	for(int i = 1; i < n; i++){
		if(ans[i] == 1)
			printf("Win ");
		else if(ans[i] == 2)
			printf("Lose ");
		else
			printf("Loop ");
	}
	puts("");
}
int main(){
	cin >> n;
	int m1, m2;
	cin >> m1;
	for(int i = 0; i < m1; i++){
		int x;
		scanf("%d", &x);
		s1.push_back(x);
	}
	cin >> m2;
	for(int i = 0 ; i < m2; i++){
		int x;
		scanf("%d", &x);
		s2.push_back(x);
	}
	solve(s1,s2);
	solve(s2,s1);
	return 0;
}