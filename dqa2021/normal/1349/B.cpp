#include<cstdio>
#include<algorithm>
using namespace std;

int n,K,w[100010];
void init(){
}
void solve(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	bool flg=0;
	for (int i=1;i<=n;i++) flg|=w[i]==K;
	if (!flg) return puts("no"),void();
	if (n==1) return puts("yes"),void();
	for (int i=1;i<n;i++){
		if (w[i]>=K&&w[i+1]>=K) return puts("yes"),void();
		if (i+2<=n&&w[i]>=K&&w[i+2]>=K) return puts("yes"),void();
	}
	puts("no");
}
int main()
{
	int T;
	for (scanf("%d",&T);T--;) init(),solve();
	return 0;
}