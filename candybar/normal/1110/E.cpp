#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[maxn],t[maxn];
vector <int> dc,dt;
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&t[i]);
	if(c[1] != t[1]){
		puts("No");
		return 0;
	}
	for(int i = 2;i <= n;i++){
		dc.push_back(c[i] - c[i - 1]);
		dt.push_back(t[i] - t[i - 1]);
	}
	sort(dc.begin(),dc.end());
	sort(dt.begin(),dt.end());
	for(int i = 0;i < (int)dc.size();i++){
		if(dc[i] != dt[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}