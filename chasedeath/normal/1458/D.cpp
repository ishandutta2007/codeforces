#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
char s[N];
int _,C[N*2][2];
int main() {
	for(scanf("%d",&_);_--;) {
		scanf("%s",s+1);
		for(int i=1,x=N;s[i];++i) C[x][s[i]-'0']++,x+=s[i]=='0'?-1:1;
		for(int i=1,x=N;s[i];++i) if(C[x][0] && C[x-1][1]) putchar('0'),C[x--][0]--;
		else if(C[x][1]) putchar('1'),C[x++][1]--;
		else putchar('0'),C[x--][0]--;
		puts("");
	}
}