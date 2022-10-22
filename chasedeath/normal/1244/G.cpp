#include<cstdio>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

//#pragma GCC optimize(2)
//#pragma GCC optimize(3)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}



const int N=1e6+10,P=1e9+7;


ll n,k;

int a[N];
int b[N];



int main(){
	cin>>n>>k;
	ll d=1ll*n*(n+1)/2;
	k-=d;
	if(k<0) return puts("-1"),0;
	reg int i,j;
	for(i=1;i<=n;++i) a[i]=b[i]=i;
	i=1,j=n;
	while(i<j) {
		if(j-i<=k) {
			k-=j-i;
			swap(b[i],b[j]);
			i++,j--;
			continue;
		}
		i++;
	}
	ll ans=0;
	rep(i,1,n) ans+=max(a[i],b[i]);
	cout<<ans<<endl;
	for(i=1;i<=n;++i) printf("%d ",a[i]); puts("");
	for(i=1;i<=n;++i) printf("%d ",b[i]); puts("");
}