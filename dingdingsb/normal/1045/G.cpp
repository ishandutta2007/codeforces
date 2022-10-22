#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+100;
int n,k;ll ans;
struct qry{
	int x,r,L,R,q;
	bool operator<(const qry rhs)const{return q<rhs.q;}
}q[N];
vector<int>num;
struct BIT{
	int tree[3*N];
	void add(int x,int y){for(;x<=(int)num.size();x+=lowbit(x))tree[x]+=y;}
	int qry(int x){int res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
	int qry(int l,int r){return qry(r)-qry(l-1);}
}T;
class CDQ{
	private:
	vector<tuple<int,int,int,int>>qs;
	// 0 a b op
	// 1 <=a [l,r]
	void cdq(int l,int r){
		if(l>=r)return;
		cdq(l,mid);cdq(mid+1,r);
		vector<tuple<int,int,int>>L,R;
		for(int i=l;i<=mid;i++)if(!get<0>(qs[i]))L.eb(get<1>(qs[i]),get<2>(qs[i]),get<3>(qs[i]));
		for(int i=mid+1;i<=r;i++)if(get<0>(qs[i]))R.eb(get<1>(qs[i]),get<2>(qs[i]),get<3>(qs[i]));
		sort(L.begin(),L.end());sort(R.begin(),R.end());
		int i=0,j=0;
		for(;i<(int)R.size();i++){
			while(j<(int)L.size()&&get<0>(L[j])<=get<0>(R[i]))
				T.add(get<1>(L[j]),get<2>(L[j])),j++;
			ans+=T.qry(get<1>(R[i]),get<2>(R[i]));
		}
		while(j--)T.add(get<1>(L[j]),-get<2>(L[j]));
	}
	public:
	void Add(int a,int b,int op){qs.eb(0,a,b,op);}
	void Qry(int a,int l,int r){qs.eb(1,a,l,r);}
	void work(){
		cdq(0,(int)qs.size()-1);
		/*for(int i=0;i<(int)qs.size();i++)if(get<0>(qs[i])){
			int op,a,l,r;tie(op,a,l,r)=qs[i];
			for(int j=0;j<i;j++)if(!get<0>(qs[j])){
				int x,y,v;tie(op,x,y,v)=qs[j];
				if(x<=a&&l<=y&&y<=r)ans+=v;
			}
		}*/
	}
}A,B;
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++)read(q[i].x,q[i].r,q[i].q),num.pb(q[i].x),num.pb(q[i].L=q[i].x-q[i].r),num.pb(q[i].R=q[i].x+q[i].r);
	sort(num.begin(),num.end());num.resize(unique(num.begin(),num.end())-num.begin());stable_sort(q+1,q+1+n);
	for(int i=1,l=1;i<=n;i++){
		q[i].L=lower_bound(num.begin(),num.end(),q[i].L)-num.begin()+1;
		q[i].R=lower_bound(num.begin(),num.end(),q[i].R)-num.begin()+1;
		q[i].x=lower_bound(num.begin(),num.end(),q[i].x)-num.begin()+1;
		while(q[l].q<q[i].q-k)
			A.Add(num.size()+1-q[l].R,q[l].x,-1),
			B.Add(q[l].L,q[l].x,-1),
			l++;
		A.Qry(num.size()+1-q[i].x,q[i].L,q[i].x);
		B.Qry(q[i].x,q[i].x+1,q[i].R);
		A.Add(num.size()+1-q[i].R,q[i].x,1);
		B.Add(q[i].L,q[i].x,1);
	}
	A.work();B.work();
	writeln(ans);
}