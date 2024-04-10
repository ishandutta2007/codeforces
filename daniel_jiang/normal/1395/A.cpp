/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,x,cnt,T;
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
		rd(a);rd(b);rd(c);rd(d);
		cnt=(a&1)+(b&1)+(c&1)+(d&1);
		x=min(a,min(b,c));
		if(x==0){
			if(cnt>1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		else{
			if(cnt==2) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}