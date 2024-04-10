#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
using namespace std;
template<class T>
void read(T&x){
	x=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<class T,class ...ARK>
void read(T&x,ARK&...ark){
	read(x);read(ark...);
}
template<class T>
void write(T x){
	if(x<0)pc('-'),x=-x;
	if(x>=10)write(x/10);
	pc(x%10+'0');
}
const int N=1e5+100;
const int mod=1e9+7;
int k,n,m;
int a[N];pair<int,int>fu[N];
vector<tuple<int,int,int>>add[N];
struct node{
	long long a,b;//a/b
	int id;int ot;int tp;
	bool operator<(const node&rhs)const{
		return (__int128)a*rhs.b<(__int128)rhs.a*b;
	}
}v[N];
int cnt=0;
int kk[N];
signed main(){
	//freopen("B.in","r",stdin);
	//freopen("a","w",stdout);
	read(k,n,m);
	for(int i=1;i<=k;i++)read(a[i]);
	for(int T=1;T<=n;T++){
		int t,i,b;read(t,i,b);
		if(t==1)chkmx(fu[i],mp(b,T));
		if(t==2)add[i].pb(make_tuple(b,T,0));
		if(t==3)if(b)v[++cnt]={b,1,0,T};
		//printf("%d %d %d   %d\n",t,i,b,cnt);
	}
	for(int i=1;i<=k;i++)if(fu[i].fi>a[i])
		add[i].pb(make_tuple(fu[i].fi-a[i],fu[i].se,1));
	for(int i=1;i<=k;i++){
		int now=a[i];
		sort(add[i].begin(),add[i].end());
		reverse(add[i].begin(),add[i].end());
		for(auto x:add[i]){
			v[++cnt]={now+get<0>(x),now,i,get<1>(x),get<2>(x)};
			now+=get<0>(x);
		}
	}
	sort(v+1,v+1+cnt);
	reverse(v+1,v+1+cnt);
	vector<int>ans1,ans2,ans3;
	//
	for(int i=1;i<=m&&i<=cnt;i++){
		if(v[i].id==0)ans3.pb(v[i].ot);
		else if(v[i].tp)ans1.pb(v[i].ot);
		else ans2.pb(v[i].ot);
	}
	write(ans1.size()+ans2.size()+ans3.size());pc('\n');
	for(auto x:ans1)write(x),pc(' ');
	for(auto x:ans2)write(x),pc(' ');
	for(auto x:ans3)write(x),pc(' ');
}