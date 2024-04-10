#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1005;

int n, m, t;

int a[maxn];

queue <int> q;

vector <pair <int, int> > vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<n;i++){
		x = read();
		y = read();
		a[x]++;
		a[y]++;
		if((x != n and y != n) or (x == n and y == n)){
			printf("NO\n");
			return 0;
		}
	}
	
	for(i=1;i<n;i++){
		if(a[i] == 0){
			q.push(i);
		}else{
			x = i;
			while(!q.empty() and a[i] > 1){
				vec.push_back(make_pair(x, q.front()));
				x = q.front();
				q.pop();
				a[i]--;
			}
			
			if(a[i] != 1){
				printf("NO\n");
				return 0;
			}
			vec.push_back(make_pair(x, n));
		}
	}
	
	if(!q.empty()){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	
	for(pair <int, int> tmp : vec){
		printf("%d %d\n", tmp.first, tmp.second);
	}
	
	return 0;
}