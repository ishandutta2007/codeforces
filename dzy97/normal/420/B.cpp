#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=1e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int n, m, a[N], vis[N], ans[N];
char op[N];
int main(){
	scanf("%d%d", &n, &m);
	char tmp[3];
	for(int i = 1;i <= n;i ++) vis[i] = ans[i] = 1;
	for(int i = 1;i <= m;i ++){
		scanf("%s%d", tmp, &a[i]);
		op[i] = tmp[0];
		vis[a[i]] = 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i ++) vis[i] = 0;
	for(int i = 1;i <= m;i ++){
		if(op[i] == '+') vis[a[i]] = 1;
		else{
			if(!vis[a[i]]) cnt ++;
		}
	}
		
	for(int i = 1;i <= m;i ++){
		if(op[i] == '+'){
			if((i > 1 && a[i] != a[i - 1]) || cnt) ans[a[i]] = 0;
			cnt ++;
		}else{
			cnt --;
			if((i < m && a[i] != a[i + 1]) || cnt) ans[a[i]] = 0;
		}
	}
	int tot = 0;
	for(int i = 1;i <= n;i ++) tot += ans[i];
	printf("%d\n", tot);
	for(int i = 1;i <= n;i ++) if(ans[i]) printf("%d ", i);
	return 0;
}