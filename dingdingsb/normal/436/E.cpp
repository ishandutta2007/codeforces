// 

// Problem: CF436E Cardboard Box
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF436E
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=3e5+100;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,a[N],b[N],id[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>
q1,q2,q3,q4,q5;
//q1 id[i]=0 a[i]
//q2 id[i]=0 b[i]
//q3 id[i]=1 b[i]-a[i]
//q4 id[i]=1 -a[i]
//q5 id[i]=2 a[i]-b[i]
void upd(int i){
	if(id[i]==0){
		q1.push(mp(a[i],i));
		q2.push(mp(b[i],i));
	}
	if(id[i]==1){
		q3.push(mp(b[i]-a[i],i));
		q4.push(mp(-a[i],i));
	}
	if(id[i]==2){
		q5.push(mp(a[i]-b[i],i));
	}
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i],b[i]),upd(i);
	ll ans=0;
	while(m--){
		while(q1.size()&&id[q1.top().se]!=0)q1.pop();
		while(q2.size()&&id[q2.top().se]!=0)q2.pop();
		while(q3.size()&&id[q3.top().se]!=1)q3.pop();
		while(q4.size()&&id[q4.top().se]!=1)q4.pop();
		while(q5.size()&&id[q5.top().se]!=2)q5.pop();
		ll kk1=inf,kk2=inf,kk3=inf,kk4=inf;
		if(q1.size())kk1=q1.top().fi;
		if(q3.size())kk2=q3.top().fi;
		if(q4.size()&&q2.size())kk3=q4.top().fi+q2.top().fi;
		if(q5.size()&&q2.size())kk4=q5.top().fi+q2.top().fi;
		ans+=min(min(kk1,kk2),min(kk3,kk4));
		if(kk1<=kk2&&kk1<=kk3&&kk1<=kk4){
			id[q1.top().se]=1;
			upd(q1.top().se);
		}else if(kk2<=kk1&&kk2<=kk3&&kk2<=kk4){
			id[q3.top().se]=2;
			upd(q3.top().se);
		}else if(kk3<=kk1&&kk3<=kk2&&kk3<=kk4){
			id[q4.top().se]=0;
			id[q2.top().se]=2;
			upd(q4.top().se);
			upd(q2.top().se);
		}else if(kk4<=kk1&&kk4<=kk2&&kk4<=kk3){
			id[q5.top().se]=1;
			id[q2.top().se]=2;
			upd(q5.top().se);
			upd(q2.top().se);
		}else exit(-1);
	}
	write(ans);pc('\n');
	for(int i=1;i<=n;i++)
		pc(id[i]+'0');
}