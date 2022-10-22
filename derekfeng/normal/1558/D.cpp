#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
typedef long long ll;
struct Comb{
	const int M=998244353,N=4e5+2;
	int fc[400005],inv[400005];
	int mypow(int x,int t){
		int ans=1,res=x;
		for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
		return ans;
	}
	void init(){
		fc[0]=1;
		for(int i=1;i<=N;i++)fc[i]=(ll)fc[i-1]*i%M;
		inv[N]=mypow(fc[N],M-2);
		for(int i=N;i;i--)inv[i-1]=(ll)inv[i]*i%M;
	}
	int C(int a,int b){
		return a<b?0:(ll)fc[a]*inv[b]%M*inv[a-b]%M;
	}
}cb;
struct BIT{
	ll bit1[200005],bit2[200005];
	const int N=2e5;
	void init(){
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
	}
	void add(int id,ll x,ll y){
		for(;id<=N;id+=(id&-id))bit1[id]+=x,bit2[id]+=y;
	}
	void upd(int l,int r,ll x){
		add(l,x,-x*(l-1)),add(r+1,-x,x*r);
	}
	ll ask(int id){
		ll res1=0,res2=0,x=id;
		for(;id;id-=(id&-id))res1+=bit1[id],res2+=bit2[id];
		return res1*x+res2;
	}
	ll qry(int l,int r){
		return ask(r)-ask(l-1);
	}
}tr;
int Tc,n,m;
int a[200005],b[200005];
int findrank(int x){
	int l=0,r=n+1;
	while(r>l+1){
		int mid=(l+r>>1);
		if(tr.qry(1,mid)>=x)r=mid;
		else l=mid;
	}
	return r;
}
set<pii>st;
void putout(int len){
	if(len==0)return;
	int w=len;
	for(;;){
		auto it=--st.end();
		int L=(*it).fi,R=(*it).se;
		st.erase(it);
		int Len=R-L+1;
		if(w>=Len){
			tr.upd(L,R,-1); 
			w-=Len;
		}else{
			tr.upd(R-w+1,R,-1); 
			R-=w,w=0;
			st.insert(make_pair(L,R));
		}
		if(w==0)break;
	}
}
void solve(){
	int K=0;
	scanf("%d%d",&n,&m);
	tr.upd(1,n,1),st.insert(mkp(1,n));
	for(int i=1;i<=m;i++)scanf("%d%d",&a[i],&b[i]);
	int lst=n+1;
	for(int i=m;i;i--){
		putout(lst-a[i]-1);
		int rk=findrank(b[i]);tr.upd(rk,rk,-1);
		auto it=--st.lower_bound(make_pair(rk,1e9));
		int L=(*it).fi,R=(*it).se;
		st.erase(it);
		if(rk!=R)K++;
		if(rk!=L)st.insert(make_pair(L,rk-1));
		if(rk!=R)st.insert(make_pair(rk+1,R));
		lst=a[i];
	}
	putout(lst-1);
	printf("%d\n",cb.C(n*2-K-1,n));
}
int main(){
	cb.init();
	tr.init();
	for(scanf("%d",&Tc);Tc--;solve());
}