#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, P = 1000000007;
int T, ans, n, x;
char s[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%s", &x, s+1), ans=n=strlen(s+1);
		for(int i=1; i<=x; ++i){
			int m=n;
			for(int j=1; j<s[i]-'0'; ++j)
				for(int k=i+1; k<=m && n<x; ++k) s[++n]=s[k];
			ans=(ans+(ll)(s[i]-'1')*(P+ans-i))%P;
		}
		printf("%d\n", ans);
	}
	return 0;
}