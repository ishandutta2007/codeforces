#include<cstdio>
#include<queue>
typedef long long ll;
const ll X=1e13;
const int N=2e5+3;
struct node{
	int p;ll d;
	bool operator<(const node&b)const{return d>b.d;}
};
int n,m,k,p,h[N],a[N],la[N];ll b[N];
inline bool Check(ll g){
	ll s=0;
	std::priority_queue<node>q;
	for(int i=1;i<=n;i++){
	  b[i]=g-a[i];
	  la[i]=0;
	  q.push((node){i,b[i]/a[i]+1});
	}
	for(int j=1,i;j<m;j++){
	  s+=k;
	  for(;!q.empty()&&q.top().d==j;){
		i=q.top().p,q.pop();
		b[i]-=(ll)(j-la[i])*a[i];
		for(;b[i]<0;){b[i]+=p,--s;if(s<0)return 0;}
		la[i]=j;
		q.push((node){i,j+b[i]/a[i]+1});
	  }
	}
	s+=k;
	for(int i=1;i<=n;i++)if(b[i]-(ll)(m-1-la[i])*a[i]<h[i])
	  s-=(h[i]-(b[i]-(ll)(m-1-la[i])*a[i])-1)/p+1;
	return s>=0;
}
signed main(){
	ll l=X,r=X,md;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",h+i,a+i),l=std::min(l,(ll)a[i]);
	for(;l<r;)md=l+r>>1,Check(md)?r=md:l=md+1;
	printf("%lld\n",l);
	return 0;
}