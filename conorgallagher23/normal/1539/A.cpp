#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
LL read(){
	char ch=getchar(); LL x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}

void solve(){
	LL n=read(),x=read(),t=read();
	LL c=t/x,d=min(c,n-1);
	cout<<d*(d+1LL)/2LL+(n-1-d)*c<<'\n';
}

int main(){
	int T=read();
	while(T--) solve();
	return 0;
}