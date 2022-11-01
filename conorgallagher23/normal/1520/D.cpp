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

int n;
LL ans;
map<LL,LL> ct;
void solve(){
	ct.clear(); ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		ans+=1LL*ct[x-i];
		ct[x-i]++;
	}
	cout<<ans<<'\n';
}

int main(){
	int T=read();
	while(T--) solve();
	return 0;
}