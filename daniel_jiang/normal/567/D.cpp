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

const int N=2e5+5;
int n,k,a,m,s[N],ans;

struct range{
	int l,r;
	range(int L,int R=-1):l(L),r(R){}
	bool operator < (range x) const{return l<x.l;}
};
set<range> qaq;
#define IT set<range>::iterator

inline void split(int pos){
	IT tmp=qaq.lower_bound(range(pos));
	if(tmp!=qaq.end()&&tmp->l==pos){
		int l=tmp->l,r=tmp->r;
		ans+=-(r-l+1+1)/(a+1)+(r-l+1)/(a+1);
		qaq.erase(tmp);qaq.insert(range(l+1,r));
		return ;
	}
	--tmp;int l=tmp->l,r=tmp->r;
	qaq.erase(tmp);qaq.insert(range(l,pos-1));
	if(r>pos) qaq.insert(range(pos+1,r)).first,ans+=(r-pos-1+1+1)/(a+1);
	ans+=-(r-l+1+1)/(a+1)+(pos-1-l+1+1)/(a+1);
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(k);rd(a);rd(m);
	for(re i=1;i<=m;++i) rd(s[i]);qaq.insert(range(1,n));ans=(n+1)/(a+1);
	for(re i=1;i<=m;++i){
		split(s[i]);
		if(ans<k){wr(i);puts("");return 0;}
	}
	puts("-1");
	return 0;
}

// ---------- Main ---------- //