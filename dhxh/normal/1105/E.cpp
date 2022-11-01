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

int n, m, t;

vector <int> vec;

bool a[55][55];

map <string, int> s;
int sc = 0;

int f[(1 << 21)];
int g[(1 << 21)];

int va[55];
int vb[55];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int getn(string str){
	if(!s[str]){
		s[str] = ++sc;
	}
	
	return s[str];
}

int getp(int x, int p){
	return (x >> (p - 1)) & 1;
}

int addp(int x, int p){
	return x | (1 << (p - 1));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int i, j, k;
	int op;
	string str;
	int hf;
	int ans = 0;
	
	cin >> n >> m;
	
	hf = m / 2 + 1;
	
	for(i=1;i<=n;i++){
		cin >> op;
		if(op == 1){
			for(k=0;k<vec.size();k++){
				for(j=k+1;j<vec.size();j++){
					a[vec[k]][vec[j]] = true;
					a[vec[j]][vec[k]] = true;
				}
			}
			vec.clear();
		}else{
			cin >> str;
			vec.push_back(getn(str));
		}
	}
	
	for(k=0;k<vec.size();k++){
		for(j=k+1;j<vec.size();j++){
			a[vec[k]][vec[j]] = true;
			a[vec[j]][vec[k]] = true;
		}
	}
	
	for(i=1;i<=hf;i++){
		for(j=1;j<=hf;j++){
			if(a[i][j]){
				va[i] = addp(va[i], j);
			}
		}
	}
	
	for(i=1;i<=(m-hf);i++){
		for(j=1;j<=(m-hf);j++){
			if(a[i + hf][j + hf]){
				va[i + hf] = addp(va[i + hf], j);
			}
		}
	}
	
	for(i=1;i<=hf;i++){
		for(j=1;j<=(m-hf);j++){
			if(a[i][j + hf]){
				vb[j + hf] = addp(vb[j + hf], i);
			}
		}
	}
	
	for(i=0;i<(1<<hf);i++){
		for(j=1;j<=hf;j++){
			if(!getp(i, j)){
				bool flag = i & va[j];
				
				if(flag){
					f[addp(i, j)] = max(f[addp(i, j)], f[i]);
				}else{
					f[addp(i, j)] = max(f[addp(i, j)], f[i] + 1);
				}
			}
		}
		ans = max(ans, f[i]);
	}
	
	for(i=0;i<(1<<(m-hf));i++){
		for(j=1;j<=(m-hf);j++){
			if(!getp(i, j)){
				bool flag = i & va[hf + j];
				
				if(flag){
					g[addp(i, j)] = max(g[addp(i, j)], g[i]);
				}else{
					g[addp(i, j)] = max(g[addp(i, j)], g[i] + 1);
				}
			}
		}
		ans = max(ans, g[i]);
	}
	
	for(i=0;i<(1<<hf);i++){
		int tmp = 0;
		for(j=1;j<=(m-hf);j++){
			bool flag = i & vb[j + hf];
			
			if(!flag){
				tmp = addp(tmp, j);
			}
		}
		
		ans = max(ans, f[i] + g[tmp]);
	}
	
	cout << ans << endl;
	
	return 0;
}