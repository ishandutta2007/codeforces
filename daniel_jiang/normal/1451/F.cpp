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

const int N=105;
int T,n,m,sum[N<<1],ans;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);rd(m);int qaq;
		memset(sum,0,sizeof(sum));
		for(re i=1;i<=n;i++)
			for(re j=1,x;j<=m;j++) rd(x),sum[i+j]^=x;
		for(qaq=2;qaq<=n+m;qaq++) if(sum[qaq]){puts("Ashish");break;}
		if(qaq==n+m+1) puts("Jeel");
	}
	return 0;
}

// ---------- Main ---------- //