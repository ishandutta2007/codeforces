// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=5005,INF=1;
int n,a[N],T;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(T);
	while(T--){
		rd(n);bool op=1;
		vector<int> ans;
		for(re i=1;i<=n;++i) rd(a[i]);
		for(re i=1;i<=n;++i)
			if((a[i]&1)!=(i&1)){puts("-1");op=0;break;}
		if(!op) continue;
		for(re i=n;i>=3;i-=2){
			int pos=1;
			for(re j=1;j<=i;++j)
				if(a[j]==i){pos=j;break;}
			ans.pb(pos);
			reverse(a+1,a+pos+1);
			for(re j=1;j<=i;++j)
				if(a[j]==i-1){pos=j;break;}
			ans.pb(pos-1);reverse(a+1,a+pos);
			ans.pb(pos+1);reverse(a+1,a+pos+2);
			ans.pb(3);reverse(a+1,a+4);
			ans.pb(i);reverse(a+1,a+i+1);
		}
		wr(ans.size());puts("");
		for(re i=0;i<ans.size();++i) wr(ans[i]),putchar(' ');puts("");
	}
	return 0;
}

// ---------- Main ---------- //