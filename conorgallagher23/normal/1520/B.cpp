#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}

LL p[11111],cnt;
void solve(){
	LL x=read(),ans=0;
	for(int i=1;i<=cnt;i++){
		if(p[i]<=x) ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	for(int i=1;i<=9;i++){
		LL tmp=i;
		for(int j=1;;j++){
			if(tmp<=1e9) p[++cnt]=tmp;
			else break;
			tmp=tmp*10LL+1LL*i;
		}
	}
	sort(p+1,p+cnt+1);
	int T=read();
	while(T--) solve();
	return 0;
}