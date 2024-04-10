#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <cmath>
#include <iostream>
#define maxn 100009
using namespace std;
bool vis[maxn];
int main(){
	int n;
	scanf("%d", &n);
	int cur = n;
	for(int i = 1;i <= n; i++){
		int x;
		scanf("%d", &x);
		vis[x] = 1;
		while(vis[cur]){
			printf("%d ",cur);
			cur--;
		}
		puts("");
	}
	return 0;
}