#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 105;
int n, cnt, a[N], b[N];
char s[N];
int main() {
	scanf("%d%s", &n, s);
	for(int i=0; i<n; ++i) scanf("%d%d", a+i, b+i), cnt+=s[i]=='1';
	int ans=cnt;
	for(int i=1; i<=130; ++i){
		for(int j=0; j<n; ++j) if(i>=b[j] && (i-b[j])%a[j]==0)
			cnt-=s[j]=='1', s[j]^=1, cnt+=s[j]=='1';
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}