#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, x, y;
char s[N];
int main() {
	scanf("%s", s+1), n=strlen(s+1);
	for(int i=1; i<=n; ++i) x+=s[i]==')';
	for(int i=1; i<=n; ++i){
		x-=s[i]==')', y+=s[i]=='(';
		if(x==y){
			if(!x) return puts("0"), 0;
			puts("1");
			printf("%d\n", x+y);
			for(int j=1; j<=n; ++j) if((j<=i)==(s[j]=='(')) printf("%d ", j);
			return 0;
		}
	}
	puts("0");
	return 0;
}