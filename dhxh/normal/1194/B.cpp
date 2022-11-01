#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

vector <vector <int> > vec;
vector <int> suma;
vector <int> sumb;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		n = read();
		m = read();
		
		vec.clear();
		suma.clear();
		sumb.clear();
		
		vector <int> e;
		
		for(j=0;j<=m;j++){
			e.push_back(0);
			suma.push_back(0);
		}
		
		for(i=0;i<=n;i++){
			vec.push_back(e);
			sumb.push_back(0);
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				char ch;
				scanf(" %c", &ch);
				if(ch == '*'){
					vec[i][j] = 1;
				}
				suma[j] += vec[i][j];
				sumb[i] += vec[i][j];
			}
		}
		
		int ans = 1e9 + 7;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				ans = min(ans, n + m - 1 - (suma[j] + sumb[i] - vec[i][j]));
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}