#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

vector <int> e[maxn];
bool vis[maxn];

vector <int> ans;
map <int, int> s;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			int cnt = 1;
			vis[i] = true;
			
			vector <int> a;
			vector <int> b;
			
			a.push_back(i);
			
			while((int)a.size() > 0){
				s.clear();
				b.clear();
				
				for(auto x : a){
					for(auto y : e[x]){
						s[y]++;
					}
				}
				
				for(j=1;j<=n;j++){
					if(!vis[j]){
						if(s[j] != (int)a.size()){
							vis[j] = true;
							cnt++;
							b.push_back(j);
						}
					}
				}
				
				a = b;
			}
			ans.push_back(cnt);
		}
	}
	
	sort(ans.begin(), ans.end());
	
	printf("%d\n", (int)ans.size());
	
	for(auto x : ans){
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}