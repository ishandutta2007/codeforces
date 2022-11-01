#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	t = read();
	
	while(t--){
		n = read();
		set <int> s;
		for(i=1;i<=n;i++){
			x = read();
			s.insert(x);
		}
		printf("%d\n", (int)s.size());
	}
	
	return 0;
}