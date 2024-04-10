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
int n,m,k,b[maxn];
vector <int> lis;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&b[i]);
	for(int i = 2;i <= n;i++) lis.push_back(b[i] - b[i - 1] - 1);
	sort(lis.begin(),lis.end(),greater<int>());
	int ans = b[n] - b[1] + 1;
	for(int i = 2;i <= k;i++){
		ans -= lis[i - 2];
	}
	printf("%d\n",ans);
	return 0;
}