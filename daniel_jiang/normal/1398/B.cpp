#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,qaq[105],cnt,nw,ans;
char s[105];
void rd(ll &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		ans=nw=cnt=0;
		scanf("%s",s);
		nw=(s[0]=='1');
		ll len=strlen(s);
		for(ll i=1;i<len;i++)
			if(s[i]=='1') nw++;
			else if(nw) qaq[++cnt]=nw,nw=0;
		if(nw) qaq[++cnt]=nw;
		sort(qaq+1,qaq+1+cnt);
		for(ll i=cnt;i>0;i-=2) ans+=qaq[i];
		wr(ans);puts("");
	}
	return 0;
}