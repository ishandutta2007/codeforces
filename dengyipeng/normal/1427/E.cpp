#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define maxm 20000
#define ll long long 
using namespace std;

ll n,i,j,k,c,ans[maxm][3];
map<ll,int> s;

ll Plus(ll x,ll y){
	if (!s[x+y]) c++,ans[c][0]=0,ans[c][1]=x,ans[c][2]=y,s[x+y]=1;
	return x+y;
}
ll Xor(ll x,ll y){
	if (!s[x^y]) c++,ans[c][0]=1,ans[c][1]=x,ans[c][2]=y,s[x^y]=1;
	return x^y;
}

int main(){
	scanf("%lld",&n),s[n]=1;
	while (n>1){
		for(k=30;k>=0;k--) if (n>>k&1) break;
		ll x=n,y,z,p,t;
		for(i=1;i<=k;i++) x=Plus(x,x);
		y=Xor(x,n);
		z=Plus(x,y);
		p=Xor(z,n);
		x=Plus(x,x);
		t=Xor(x,p);
		x>>=1;
		while (t<=x){
			if (t&x) x=Xor(x,t);
			t=Plus(t,t);
		}
		n=Xor(n,x);
	}
	printf("%d\n",c);
	for(i=1;i<=c;i++) {
		printf("%lld ",ans[i][1]);
		putchar(ans[i][0]?'^':'+');
		printf("% lld\n",ans[i][2]);
	}
}