#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<Int, P> T;
Int u[108000], a[108000], sz[108000];
Int n, m, x, y;
Int res;

Int r(Int x){
	if(u[x] == x)return x;
	return u[x] = r(u[x]);
}

void unin(Int a, Int b){
	a = r(a);
	b = r(b);
	u[a] = b;
}

int main(){
	for(Int i = 0;i < 108000;i++)u[i] = i, sz[i] = 1;
	vector<T> edge;
	cin >> n >> m;
	for(Int i = 0;i < n;i++)cin >> a[i];
	for(Int i = 0;i < m;i++){
		cin >> x >> y;
		x--,y--;
		edge.push_back(T(min(a[x], a[y]), P(x, y)));
	}
	sort(edge.begin(), edge.end());
	while(!edge.empty()){
		P tmp = edge.back().second;
		Int cost = edge.back().first;
		edge.pop_back();
		Int x = tmp.first, y = tmp.second;
		x = r(x), y = r(y);
		if(x == y)continue;
		res += cost * sz[x] * sz[y];
		Int nextsz = sz[x] + sz[y];
		unin(x, y);
		x = r(x);
		sz[x] = nextsz;
	}
	res *= 2;
	printf("%.9lf\n", (double)res / (n * (n - 1)));
	return 0;
}