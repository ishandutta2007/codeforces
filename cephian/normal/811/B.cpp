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

const int N = 1e4+5;
int p[N],n,m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; ++i)
		scanf("%d",p+i);
	while(m--) {
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		int a = 0;
		for(int i = l; i <= r; ++i)
			a += p[i] < p[x];
		if(a == x-l) printf("Yes\n");
		else printf("No\n");
	}


	return 0;
}