#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 55;
int a[N];
bool ok[N];

int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n-k+1; ++i) {
		char s[32];
		scanf("%s",s);
		ok[i] = (s[0] == 'Y');
	}

	for(int i = 0; i < n; ++i) {
		a[i] = i+1;
	}

	for(int i = k-1; i < n; ++i)
		if(!ok[i-k+1])
			a[i] = a[i-k+1];
	
	for(int i = 0; i < n; ++i) {
		printf("X");
		while(a[i]) {
			if(a[i]&1) printf("a");
			else printf("b");
			a[i]/=2;
		}
		printf("\n");
	}

	return 0;
}