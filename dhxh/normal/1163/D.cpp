#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int inf = 0x3f3f3f3f;

int n, m, t;

string a, b, str;

int na[55];
int nb[55];

int f[1005][55][55];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int getnext(){
	int i, j;
	
	na[0] = 0;
	na[1] = 0;
	
	for(i=2;i<=n;i++){
		j = na[i - 1];
		while(j and a[j + 1] != a[i]){
			j = na[j];
		}
		
		if(a[j + 1] == a[i]){
			na[i] = j + 1;
		}else{
			na[i] = 0;
		}
	}
	
	nb[0] = 0;
	nb[1] = 0;
	
	for(i=2;i<=m;i++){
		j = nb[i - 1];
		while(j and b[j + 1] != b[i]){
			j = nb[j];
		}
		
		if(b[j + 1] == b[i]){
			nb[i] = j + 1;
		}else{
			nb[i] = 0;
		}
	}
		
	return 0;
}

int main(){
	int i, j, k, l;
	int x, y;
	
	cin >> str >> a >> b;
	
	n = a.length();
	m = b.length();
	
	a = '0' + a;
	b = '0' + b;
	
	str = '0' + str;
	
	getnext();
	
	for(i=0;i<=str.length();i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=m;k++){
				f[i][j][k] = -inf;
			}
		}
	}
	
	f[0][0][0] = 0;
	
	for(i=1;i<str.length();i++){
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				if(str[i] != '*'){
					int tmp = f[i - 1][j][k];
					x = j, y = k;
					bool flag = false;
					if(str[i] == a[x + 1]){
						if(x + 1 == n){
							tmp++;
							x = na[x + 1];
							flag = true;
						}
					}else{
						x = na[x];
						while(x and str[i] != a[x + 1]){
							x = na[x];
						}
					}
					if(!flag and str[i] == a[x + 1]){
						x++;
					}
					
					flag = false;
					if(str[i] == b[y + 1]){
						if(y + 1 == m){
							tmp--;
							y = nb[y + 1];
							flag = true;
						}
					}else{
						y = nb[y];
						while(y and str[i] != b[y + 1]){
							y = nb[y];
						}
					}
					if(!flag and str[i] == b[y + 1]){
						y++;
					}
					
					f[i][x][y] = max(f[i][x][y], tmp);
				}else{
					for(l=0;l<26;l++){
						int tmp = f[i - 1][j][k];
						x = j, y = k;
						bool flag = false;
						if('a' + l == a[x + 1]){
							if(x + 1 == n){
								tmp++;
								x = na[x + 1];
								flag = true;
							}
						}else{
							x = na[x];
							while(x and 'a' + l != a[x + 1]){
								x = na[x];
							}
						}
						if(!flag and 'a' + l == a[x + 1]){
							x++;
						}
						
						flag = false;
						if('a' + l == b[y + 1]){
							if(y + 1 == m){
								tmp--;
								y = nb[y + 1];
								flag = true;
							}
						}else{
							y = nb[y];
							while(y and 'a' + l != b[y + 1]){
								y = nb[y];
							}
						}
						if(!flag and 'a' + l == b[y + 1]){
							y++;
						}
						
						f[i][x][y] = max(f[i][x][y], tmp);
					}
				}
			}
		}
	}
	
	int ans = -inf;
	
	for(j=0;j<n;j++){
		for(k=0;k<m;k++){
			ans = max(ans, f[str.length() - 1][j][k]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}