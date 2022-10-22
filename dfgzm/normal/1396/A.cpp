#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=200010;
int i,j,k,n,m;
int B[maxn];
ll a[maxn],t[maxn];
int main() {
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=read(),B[i]=a[i]<0?-1:1,a[i]=abs(a[i]);
	ll s=0;
	for(i=1;i<=n;i++){
		s+=n-1;
		t[(s-1)%n+1]=i;
	}
	if(n==1){
		printf("1 1\n%lld\n",-a[1]*B[1]);
		printf("1 1\n%d\n",0);
		printf("1 1\n%d\n",0);
	}else{
		printf("1 %d\n",n-1);
		for(i=1;i<n;i++){
			printf("%lld ",1ll*t[n-a[i]%n]*(n-1)*B[i]);
			a[i]+=1ll*t[n-a[i]%n]*(n-1);
		}puts("");
		printf("%d %d\n",n,n);
		printf("%lld\n",(n-a[n]%n)*B[i]);
		a[n]+=n-a[n]%n;
		printf("%d %d\n",1,n);
		for(i=1;i<=n;i++){
			printf("%lld ",-a[i]*B[i]);
		}puts("");
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}