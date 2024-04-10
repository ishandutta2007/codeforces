/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,x,T;
char s[N];
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		scanf("%s",s+1);
		rd(x);n=strlen(s+1);
		bool ans[N]={0},ok=0;
		for(ll i=1;i<=n;i++)
			if(s[i]=='0'){
				if(i-x>0) ans[i-x]=1;
				if(i+x<=n) ans[i+x]=1;
			}
		for(ll i=1;i<=n;i++)
			if(s[i]=='1'&&(i-x<=0||ans[i-x])&&(i+x>n||(i+x<=n&&ans[i+x]))){
				cout<<"-1";puts("");ok=1;break;
			}
		if(ok) continue;
		for(ll i=1;i<=n;i++) wr(1-ans[i]);puts("");
	}
	return 0;
}