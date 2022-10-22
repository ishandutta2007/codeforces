#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10,P=1e9+7;

int n,m;
char s[N];

struct Suffix_Array{
	int rk[N<<1],tmp[N],st[20][N],cnt[N],sa[N],Log[N],lcp[N];
	void Build() {
		rep(i,1,n) cnt[s[i]-'a']++;
		rep(i,1,25) cnt[i]+=cnt[i-1];
		rep(i,1,n) rk[i]=cnt[s[i]-'a'];
		drep(i,n,1) sa[cnt[s[i]-'a']--]=i;
		for(int m=n,k=1;;k<<=1) {
			int h=0;
			rep(i,n-k+1,n) tmp[++h]=i;
			rep(i,1,n) if(sa[i]>k) tmp[++h]=sa[i]-k;
		
			rep(i,1,n) cnt[rk[sa[i]]]=i;
			drep(i,n,1) sa[cnt[rk[tmp[i]]]--]=tmp[i];
			rep(i,0,m) cnt[i]=0;
			
			rep(i,1,n) tmp[sa[i]]=tmp[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i-1]+k]!=rk[sa[i]+k]);
			rep(i,1,n) rk[i]=tmp[i];
			if((m=rk[sa[n]])==n) break;
		}
		int h=0;
		rep(i,1,n) {
			int j=sa[rk[i]-1];
			if(h) h--;
			while(s[i+h]==s[j+h]) h++;
			lcp[rk[i]-1]=h;
		}
		rep(i,2,n) Log[i]=Log[i>>1]+1;
		rep(i,1,n) st[0][i]=lcp[i];
		rep(i,1,Log[n]) {
			int len=1<<(i-1);
			rep(j,1,n-len+1) st[i][j]=min(st[i-1][j],st[i-1][j+len]);
		}
	}
	int LCP(int i,int j) {
		if(i==j) return n-sa[i]+1;
		if(i>j) swap(i,j);
		j--;
		int d=Log[j-i+1];
		return min(st[d][i],st[d][j-(1<<d)+1]);
	}
} S;

int rk[N<<1],tmp[N],cnt[N],sa[N],lcp[N];
void Build() {
	rep(i,1,n) cnt[s[i]-'a']++;
	rep(i,1,25) cnt[i]+=cnt[i-1];
	rep(i,1,n) rk[i]=cnt[s[i]-'a'];
	drep(i,n,1) sa[cnt[s[i]-'a']--]=i;
	for(int m=n,k=1;;k<<=1) {
		int h=0;
		rep(i,n-k+1,n) tmp[++h]=i;
		rep(i,1,n) if(sa[i]>k) tmp[++h]=sa[i]-k;
	
		rep(i,1,n) cnt[rk[sa[i]]]=i;
		drep(i,n,1) sa[cnt[rk[tmp[i]]]--]=tmp[i];
		
		rep(i,1,n) tmp[sa[i]]=tmp[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i-1]+k]!=rk[sa[i]+k]);
		rep(i,1,n) rk[i]=tmp[i];
		if((m=rk[sa[n]])==n) break;
	}
	//rep(i,1,n) cout<<sa[i]<<' ';
	//puts("");
	//rep(i,1,n) cout<<rk[i]<<' ';
	//puts("");
	int h=0;
	rep(i,1,n) {
		int j=sa[rk[i]-1];
		if(h) h--;
		while(s[i+h]==s[j+h]) h++;
		lcp[rk[i]-1]=h;
	}
}

int stk[N],top,ls[N],rs[N],mk[N];
ll ans;

ll F[N*2];
set <int> st[N*2];
void dfs(int &u,int l,int r,int lst){
	//cout<<"dfs "<<u<<' '<<l<<' '<<r<<' '<<lst<<endl;
	if(l==r) {
		u=++m;
		int p=sa[l];
		if(p>2) {
			int q=n-(p-2)+1;
			F[u]=n-q+1;
			st[u].insert(S.rk[q]);
		}
		if(p>1) {
			ans+=1ll*(n-p+1-lst)*(F[u]+1);
			//cout<<"$"<<p<<' '<<lst<<' '<<n-p+1-lst<<' '<<F[u]<<endl;
			//cout<<ans<<endl;
		}
		return;
	}
	dfs(ls[u],l,u,lcp[u]),dfs(rs[u],u+1,r,lcp[u]);
	if(st[ls[u]].size()>st[rs[u]].size()) swap(ls[u],rs[u]);
	swap(st[u],st[rs[u]]);
	F[u]=F[ls[u]]+F[rs[u]];

	int t=-1;
	for(int i:st[ls[u]]){
		if(~t) F[u]+=S.LCP(t,i);
		t=i;
	}

	for(int i:st[ls[u]]) {
		auto r=st[u].upper_bound(i);
		if(r!=st[u].end()) F[u]-=S.LCP(i,*r);
		if(r!=st[u].begin()) {
			auto l=r; l--;
			if(r!=st[u].end()) F[u]+=S.LCP(*l,*r);
			F[u]-=S.LCP(*l,i);
		}
		st[u].insert(i);
	}
	//cout<<l<<' '<<r<<' '<<F[u]<<' '<<lcp[u]-lst<<endl;
	ans+=1ll*(lcp[u]-lst)*(F[u]+1);
}

int main(){
	scanf("%s",s+1),n=m=strlen(s+1);
	if(n==1) return puts("3"),0;
	Build(),reverse(s+1,s+n+1),S.Build();
	//puts("!");
	rep(i,1,n-1) {
		while(top && lcp[stk[top]]>lcp[i]) ls[i]=stk[top--];
		if(top) rs[stk[top]]=i;
		stk[++top]=i;
	}
	//puts("!");
	rep(i,1,n-1) mk[ls[i]]=mk[rs[i]]=1;

	rep(i,1,n) ans+=n-i+1-lcp[i];
	ans++;

	int lst=-1;
	rep(i,1,n) if(S.sa[i]>1) {
		ans+=n-S.sa[i]+1;
		//cout<<n-S.sa[i]<<endl;
		if(~lst) ans-=min(S.LCP(i,lst),min(n-S.sa[i]+1,n-S.sa[lst]+1));
		lst=i;
	}
	ans++;
	//cout<<ans<<endl;

	rep(i,1,n-1) {
		assert(i>=0);
		if(!mk[i]) dfs(i,1,n,0);
	}
	printf("%lld\n",ans);
}