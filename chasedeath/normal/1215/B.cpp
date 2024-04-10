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

const int N=1<<21;

int n;
int a[N];
int cnt[2];
ll ans[2];

int main(){
	rep(i,1,n=rd()) a[i]=rd()<0;
	cnt[0]++;
	rep(i,1,n) {
		a[i]^=a[i-1];
		rep(j,0,1) ans[j]+=cnt[j^a[i]];
		cnt[a[i]]++;
	}
	printf("%I64d %I64d\n",ans[1],ans[0]);
}