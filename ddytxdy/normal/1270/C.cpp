#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int T,n;LL x,y;
void solve(){
	scanf("%d",&n);x=y=0;
	for(int i=1,a;i<=n;i++)
		scanf("%d",&a),x+=a,y^=a;
	printf("2\n%lld %lld\n",y,x+y);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}