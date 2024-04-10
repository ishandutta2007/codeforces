#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 300
using namespace std;
int n;char s[N+5];
int Q() {int t;putchar('\n'),fflush(stdout),scanf("%d",&t);return t;}
int main()
{
	int i,j,t;if(putchar('a'),(n=Q()+1)>N) {for(i=1;i<=N;++i) putchar('b');return Q();}
	for(i=1;i<=n;++i) putchar(s[i]='a');t=Q();if(t==n) {for(i=1;i^n;++i) putchar('b');return Q();}
	for(i=1;i<=n;++i) {s[i]='b';for(j=1;j<=n;++j) putchar(s[j]);Q()<t?--t:s[i]='a';if(!t) return 0;}return 0;
}