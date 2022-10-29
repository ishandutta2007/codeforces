// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

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

// ---------- IO ---------- //

ll T,d,k,qaq;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(d);rd(k);
		qaq=0;
		for(;2ll*qaq*qaq<=d*d;qaq+=k) ;
		qaq-=k;
//		cout<<qaq<<endl;
//		cout<<qaq*qaq<<' '<<qaq*(qaq+k)<<' '<<d*d<<endl;
		if(qaq*qaq+(qaq+k)*(qaq+k)<=d*d) puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}

// ---------- Main ---------- //