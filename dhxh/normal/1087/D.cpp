#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

double s;

vector <int> e[maxn];

int addedge(int x, int y){
	e[x].push_back(y);
	e[y].push_back(x);
	
	return 0;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	int cnt = 0;
	
	n = read();
	s = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		addedge(x, y);
	}
	
	for(i=1;i<=n;i++){
		if(e[i].size() == 1){
			cnt++;
		}
	}
	
	printf("%.12lf\n", s / (double)cnt * 2.0);
	
	return 0;
}