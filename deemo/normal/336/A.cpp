//I'm nothing
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int x, y;

int abs(int x){
	if (x > 0)	return	x;
	return	-x;
}

int main(){
	scanf("%d%d", &x, &y);
	int z = abs(x) + abs(y);
	pair<int, int>	a, b;
	if (x > 0)	a = {z, 0};
	else	a = {-z, 0};
	if (y > 0)	b = {0, z};
	else	b = {0, -z};
	if (a > b)	swap(a, b);
	printf("%d %d %d %d\n", a.first, a.second, b.first, b.second);
	return 0;
}