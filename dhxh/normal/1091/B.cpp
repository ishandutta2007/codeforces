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

struct ex {
	int x, y;
};

ex p[1005];
ex a[1005];

vector <pair <int, int> > q;
map <pair <int, int>, int> s;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x = 0, y = 0;
	
	n = read();
	
	for(i=1;i<=2*n;i++){
		x += read();
		y += read();
	}
	
	printf("%lld %lld\n", x / n, y / n);
	
	return 0;
}