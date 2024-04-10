#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;

int n;
ll k;
int a[N];
ll s[N];

int Check(int x) {
	for(reg int L=1,R=1;R<=n;++R) {
		while(a[R]-a[L]>x) L++;
		ll res=1ll*(L-1)*(a[R]-x)-s[L-1];
		res+=(s[n]-s[R-1])-1ll*(n-R+1)*a[R];
		if(res<=k) return 1;
	}
	for(reg int L=1,R=1;L<=n;L++) {
		while(a[R+1]-a[L]<=x) R++;
		ll res=1ll*L*a[L]-s[L];
		res+=(s[n]-s[R])-1ll*(n-R)*(a[L]+x);
		if(res<=k) return 1;
	}
	return 0;
}


int main(){ 
	n=rd(); cin>>k;
	rep(i,1,n) a[i]=rd();
	a[n+1]=2e9;
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int l=0,r=1e9,res=-1;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(Check(mid)) r=mid-1,res=mid;
		else l=mid+1;
	}
	printf("%d\n",res);
}