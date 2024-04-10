#include <bits/stdc++.h>
using namespace std;

map<int,int> m;

int main() {	
	int n,a;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a);
		++m[a];
	}
	for(auto p : m) {
		if(p.second&1) {
			printf("Conan\n");
			return 0;
		}
	}
	printf("Agasa\n");
}