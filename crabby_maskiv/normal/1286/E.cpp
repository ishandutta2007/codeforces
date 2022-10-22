#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
const ll mask=(1<<30)-1;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
int nxt[N],f[N];
char a[N];
struct sgt{
	int l,r,ls,rs;
	int cnt;
	ll sum,lw,rw,tag;
}s[3*N];
int rt,P;
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].lw=s[p].rw=s[p].tag=inf;
	if(l==r) return p;
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
inline void upd(int p){
	s[p].sum=s[s[p].ls].sum+s[s[p].rs].sum;
	s[p].lw=s[s[p].ls].lw;
	s[p].rw=s[s[p].rs].rw;
	s[p].cnt=s[s[p].ls].cnt+s[s[p].rs].cnt;
}
inline void pushd(int p){
	if(s[p].tag==inf) return;
	s[p].sum=s[p].cnt*s[p].tag;
	s[p].lw=s[p].rw=s[p].tag;
	if(s[p].ls) s[s[p].ls].tag=s[p].tag;
	if(s[p].rs) s[s[p].rs].tag=s[p].tag;
	s[p].tag=inf;
}
void chg1(int p,int pos,int x){
	pushd(p);
	if(s[p].l==s[p].r){
		s[p].cnt=x;
		s[p].sum=x*s[p].lw;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid){
		chg1(s[p].ls,pos,x);
		pushd(s[p].rs);
	}
	else{
		chg1(s[p].rs,pos,x);
		pushd(s[p].ls);
	}
	upd(p);
}
void chg2(int p,int r,ll x){
	pushd(p);
	if(s[p].l>r) return;
	if(s[p].r<=r){
		if(s[p].lw>=x){
			s[p].tag=x;
			pushd(p);
		}
		else if(s[p].rw>x){
			chg2(s[p].ls,r,x);
			chg2(s[p].rs,r,x);
			upd(p);
		}
		return;
	}
	chg2(s[p].ls,r,x);
	chg2(s[p].rs,r,x);
	upd(p);
}
inline void print(__int128 x){
	static char s[25];
	int t=0;
	if(!x) s[++t]='0';
	while(x){
		s[++t]='0'+(x%10);
		x/=10;
	}
	while(t) cout<<s[t--];
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j;
	cin>>n;
	__int128 ans=0;
	rt=build(1,n);
	chg1(rt,1,1);
	for(i=1;i<=n;i++){
		char ch;int w;cin>>ch>>w;
		ch=(ch-'a'+ans)%26+'a';
		w=(w^(ans&mask));
		a[i]=ch;
		if(a[i]==a[nxt[i-1]+1]) f[i-1]=f[nxt[i-1]];
		else f[i-1]=nxt[i-1];
		for(j=nxt[i-1];j&&a[j+1]!=a[i];j=nxt[j]);
		if(i>1) nxt[i]=j+(a[j+1]==a[i]);
		if(a[i]==a[1]) chg1(rt,i,1);
		chg2(rt,i,w);
		j=i-1;
		while(j){
			if(a[j+1]!=a[i]){
				chg1(rt,i-j,0);
				j=nxt[j];
			}
			else j=f[j];
		}
		ans+=s[rt].sum;
		print(ans);
	}
	return 0;
}