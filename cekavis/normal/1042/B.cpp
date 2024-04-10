#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
const int N = 1005;
int n, a[N], b[N], f[N];
char s[222];
int main() {
	scanf("%d", &n);
	memset(f, 0x3f3f3f3f, sizeof f);
	for(int i=1; i<=n; ++i){
		scanf("%d%s", a+i, s);
		for(int j=0; s[j]; ++j) b[i]|=1<<(s[j]-'A');
		f[b[i]]=min(f[b[i]], a[i]);
	}
	for(int i=0; i<8; ++i) for(int j=0; j<8; ++j) for(int k=0; k<8; ++k) if(((j|k)&i)==i) f[i]=min(f[i], f[j]+f[k]);
	return printf("%d", f[7]<=1e9?f[7]:-1), 0;
}