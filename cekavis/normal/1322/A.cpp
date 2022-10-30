#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, ans, a[N];
char s[N];
int main() {
	scanf("%d%s", &n, s+1);
	for(int i=1; i<=n; ++i) a[i]=a[i-1]+(s[i]=='('?1:-1);
	if(a[n]) return puts("-1"), 0;
	for(int i=1; i<=n; ++i) if(a[i]<0){
		int j=i;
		while(a[j]) ++j;
		ans+=j-i+1;
		i=j;
	}
	printf("%d\n", ans);
	return 0;
}