#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 2005, C = 26;
int n, cnt[26];
char s[N], t[N], ss[N];
void shift(int x){
	printf("%d ", x);
	for(int i=1; i<=x; ++i) ss[i]=s[n-i+1];
	for(int i=x+1; i<=n; ++i) ss[i]=s[i-x];
	memcpy(s, ss, sizeof s);
}
int main() {
	scanf("%d%s%s", &n, s+1, t+1);
	for(int i=1; i<=n; ++i) ++cnt[s[i]-'a'], --cnt[t[i]-'a'];
	for(int i=0; i<C; ++i) if(cnt[i]) return puts("-1"), 0;
	printf("%d\n", n*3);
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j) if(s[j]==t[n-i+1]){
			shift(n), shift(j-1), shift(1);
			break;
		}
	}
	return 0;
}