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
const int N=5e6+10;
int n,k,top,pos[N],len[N],z[N],p[N];char s[N],sr[N],tmp[2*N],ans[N];
void lyndon(char*s,int n){
	for(int i=1,j,k;i<=n;){
		for(j=i,k=i+1;s[k]>=s[j];k++)
			j=s[k]==s[j]?j+1:i;
		while(i<=j)i+=k-j;
		++top,pos[top]=i-1,len[top]=k-j;
	}
}
inline void Z(char *s, int n) {
	for (int i = 1; i <= n; i++) z[i] = 0;
	z[1] = n;
	for (int i = 2, l = 0, r = 0; i <= n; i++) {
		if (i <= r) z[i] = min(z[i-l+1], r - i + 1);
		while (i + z[i] <= n && s[i+z[i]] == s[z[i]+1]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

inline void exkmp(char *s, int n, char *t, int m) {
	Z(t, m);
	for (int i = 1; i <= n; i++) p[i] = 0;
	for (int i = 1, l = 0, r = 0; i <= n; i++) {
		if (i <= r) p[i] = min(z[i-l+1], r - i + 1);
		while (i + p[i] <= n && s[i+p[i]] == t[p[i]+1]) ++p[i];
		if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
	}
}
void upd(char*s){
	//for(int i=1;i<=n;i++)pc(s[i]);pc('\n');
	for(int i=1;i<=n;i++)
		if(ans[i]<s[i])return;
		else if(ans[i]>s[i])break;
	for(int i=1;i<=n;i++)ans[i]=s[i];
}
void work1(){
	upd(s);upd(sr);
	puts(ans+1);
}
void work3(){
	for(int i=pos[top-1]+1;i<=pos[top];i++)pc(sr[i]);
	k-=(len[top]!=1||len[top-1]!=1);top--;
}
void solve1(){
	for(int i=1;i<=n;i++)tmp[i]=tmp[i+n]=sr[i];
	int o=114514;
	for(int i=1,j,k;i<=n;){
		o=i;
		for(j=i,k=i+1;tmp[k]>=tmp[j];k++)j=tmp[k]==tmp[j]?j+1:i;
		while(i<=j)i+=k-j;
	}
	upd(tmp+o-1);
}
void solve2(){
	exkmp(s,n,sr,n);reverse(p+1,p+1+n);
	int res=n;
	for(int i=n-1;i;i--){
		// sr[i,res-1]^r+sr[1,i-1]  sr[1,res-1]
		if(p[res-1]<res-i){
			if(sr[res-p[res-1]-1]<sr[p[res-1]+1])res=i;
		}else if(z[res-i+1]<i-1){
			if(sr[z[res-i+1]+1]<sr[res-i+z[res-i+1]+1])res=i;
		}
	}
	//writeln(res);
	//reverse(s+n-res+2,s+n+1);
	reverse(sr+1,sr+res);
	reverse(sr+1,sr+1+n);
	upd(sr);
	reverse(sr+1,sr+1+n);
	reverse(sr+1,sr+res);
}
void solve3(){
	int p=top+1;
	while(--p>1){
		bool flag=1;
		for(int i=pos[p-2]+1,j=pos[p-1]+1;flag&&j<=pos[p];i++,j++)
			if(sr[i]!=sr[j])flag=0;
		if(!flag)break;
	}
	int res=p;
	while(++p<=top){
		for(int i=pos[p-1],j=pos[p-2]+1+n-i;i>pos[p-2];i--,j++)if(sr[i]^sr[j]){
			if(sr[i]<sr[j])res=p;
			break;
		}
	}
	reverse(sr+pos[res-1]+1,sr+n+1);
	reverse(sr+1,sr+n+1);
	upd(sr);
}
void work2(){
	for(int i=1;i<=n;i++)s[i]=sr[i];
	reverse(s+1,s+1+n);
	upd(s);upd(sr);
	//case1sr
	solve1();
	//case2t1t2
	solve2();
	//case3t1t2
	solve3();
	puts(ans+1);
}
signed main(){
	ans[1]=127;scanf("%s",s+1);n=strlen(s+1);
	memcpy(sr,s,sizeof s);reverse(sr+1,sr+1+n);
	read(k);if(k==1)return work1(),0;
	lyndon(sr,n);
	while(k>=3&&top)work3();
	if(top)n=pos[top],work2();
	cerr<<""<<endl;
	cerr<<""<<endl;
}