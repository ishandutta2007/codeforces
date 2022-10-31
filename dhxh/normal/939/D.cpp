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

int fa[maxn];

string a, b;

vector <pair <char, char> > vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	
	if(ra != rb){
		fa[ra] = rb;
		return 1;
	}
	
	return 0;
}

int main(){
	int i, j;
	
	cin >> n;
	cin >> a >> b;
	
	for(i=1;i<=26;i++){
		fa[i] = i;
	}
	
	for(i=0;i<n;i++){
		if(find(a[i] - 'a' + 1) != find(b[i] - 'a' + 1)){
			vec.push_back(make_pair(find(a[i] - 'a' + 1) + 'a' - 1, find(b[i] - 'a' + 1) + 'a' - 1));
			join(a[i] - 'a' + 1, b[i] - 'a' + 1);
		}
	}
	
	printf("%d\n", (int)vec.size());
	
	for(pair <char, char> x : vec){
		printf("%c %c\n", x.first, x.second);
	}
	
	return 0;
}