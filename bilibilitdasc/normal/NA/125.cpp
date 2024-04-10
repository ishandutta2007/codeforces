#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
int main()
{
	int las,fir;
	printf("?");
	rep(i,100) printf(" %d",i+1);
	printf("\n");
	fflush(stdout);
	scanf("%d",&fir);
	printf("?");
	rep(i,100) printf(" %d",(i+1)<<7);
	printf("\n");
	fflush(stdout);
	scanf("%d",&las);
	printf("! %d",((fir&(((1<<7)-1)<<7))|(las&((1<<7)-1))));
	fflush(stdout);
	return 0;
}