#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, cnt, top;
char s[N], stk[N];
int main() {
	scanf("%d%s", &n, s+1);
	for(int i=1; i<=n; ++i) cnt+=s[i]=='(';
	if((n&1) || cnt!=n/2) return puts("No"), 0;
	for(int i=1; i<=n; ++i){
		if(top && s[i]==')' && stk[top]=='(') --top;
		else stk[++top]=s[i];
	}
	if(top<=2) puts("Yes"); else puts("No");
	return 0;
}