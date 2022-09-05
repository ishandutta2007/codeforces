#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 4050000, mo = 51123987;
int n,len,p[N],beg[N],fin[N]; ll tot,qz[N];
char s[N];
inline void manacher() {
	per(i,n,1) s[i*2]=s[i],s[i*2+1]='#'; s[1]='#'; 
	int id=0;
	rep(i,1,len) {
		if (id+p[id]-1>=i) p[i]=(2*id-i>=1)?min(p[2*id-i],id+p[id]-i):0;
		while (i+p[i]<=len&&i-p[i]>=1&&s[i-p[i]]==s[i+p[i]]) p[i]++;
		if (i+p[i]>id+p[id]) id=i; tot+=p[i]>>1; //printf("%d : %d\n",i,p[i]);
	}
}
int main() { //freopen("1.in","r",stdin);
	read(n); len=n*2+1; scanf("%s",s+1); manacher(); //printf("%d\n",tot);
	tot%=mo; tot=(tot==0)?mo:tot; ll ans=1LL*tot*(tot-1)/2%mo; //ans-=...
	rep(i,1,len) fin[i]++,fin[i+p[i]]--; rep(i,1,len) fin[i]+=fin[i-1];
	rep(i,1,len) beg[i-p[i]+1]++,beg[i+1]--; rep(i,1,len) beg[i]+=beg[i-1];
	rep(i,1,len) if (s[i]=='#') beg[i]=fin[i]=0;
//	rep(i,1,len) printf("%d : %d %d\n",i,beg[i],fin[i]);
	rep(i,1,len) qz[i]=qz[i-1]+fin[i];
	rep(i,1,len) ans-=qz[i-1]*beg[i]%mo;
	cout<<(ans%mo+mo)%mo;
	return 0;
}