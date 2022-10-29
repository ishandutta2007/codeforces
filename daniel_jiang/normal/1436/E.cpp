// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

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
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=1e5+5;
int n,a[N],len=350,lst[N],cnt,ans[N];

inline int block(int x){return (x-1)/len+1;}
inline int L(int x){return (x-1)*len+1;}
inline int R(int x){return x*len;}

struct question{int id,l,r,pos;}q[N<<2];

inline bool cmp(question x,question y){
	if(x.pos!=y.pos) return x.pos<y.pos;
	if(x.pos&1) return x.r<y.r;
	return x.r>y.r;
}

struct block_on_range{
	int a[N],b[N],c[N],d[N];
	inline void insert(int x){
		if(a[x]==0) c[x]=1,d[block(x)]++;
		a[x]++;b[block(x)]++;
	}
	inline void erase(int x){
		a[x]--;b[block(x)]--;
		if(a[x]==0) c[x]=0,d[block(x)]--;
	}
	inline int mex(){
		int tmp=block(n);
		for(re i=1;i<tmp;++i){
			if(len==d[i]) continue;
			for(re j=L(i);j<=R(i);++j) if(!c[j]) return j;
		}
		for(re i=L(tmp);i<=n;++i) if(!c[i]) return i;
		return n+1;
	}
}qaq;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i){
		rd(a[i]);
		if(i-lst[a[i]]>1) q[++cnt]=(question){a[i],lst[a[i]]+1,i-1,block(lst[a[i]]+1)};
		lst[a[i]]=i;
	}
	for(re i=1;i<N;++i)
		if(lst[i]&&lst[i]!=n) q[++cnt]=(question){i,lst[i]+1,n,block(lst[i]+1)};
	sort(q+1,q+cnt+1,cmp);
	int l=q[1].l+1,r=q[1].l;
	for(re i=1;i<=cnt;++i){
		while(l>q[i].l) --l,qaq.insert(a[l]);
		while(r<q[i].r) ++r,qaq.insert(a[r]);
		while(l<q[i].l) qaq.erase(a[l]),l++;
		while(r>q[i].r) qaq.erase(a[r]),r--;
		//cout<<q[i].l<<' '<<q[i].r<<' '<<q[i].id<<' '<<qaq.mex()<<endl;
		if(qaq.mex()==q[i].id) ans[q[i].id]=1;
	}
	while(l>1) --l,qaq.insert(a[l]);
	while(r<n) ++r,qaq.insert(a[r]);
	ans[qaq.mex()]=1;
	for(re i=1;i<N;++i)
		if(!ans[i]){
			wr(i);puts("");break;
		}
	return 0;
}

// ---------- Main ---------- //