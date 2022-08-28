#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %st",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int blk=1;
const int mod1=998244353,e1=31,mod2=1004535809,e2=131;
int n,m,i,j,k,q,lg[200005];
vector<int> p[200005];
long long hsh1[200005],hsh2[200005],pw1[200005],pw2[200005];
string st;
int pl[200005],pr[200005];
unordered_map<long long,vector<int> > mp[200005];
long long gth(int l,int r){return (hsh1[r]+(mod1-hsh1[l-1])*pw1[r-l+1])%mod1*mod2+(hsh2[r]+(mod2-hsh2[l-1])*pw2[r-l+1])%mod2;}
int cnt[200005][26];
int mi[200005][21];
int qry(int l,int r,int c){return cnt[r][c]-cnt[l-1][c];}
bool check_bad(int l,int r){for(int i=0;i<26;++i)if(qry(l,r,i)>1)return 0;return 1;}
bool check1(int l,int r){ff(p[r-l+1],it){int len=(r-l+1)/(*it);if(gth(l,r-len)==gth(l+len,r))return 1;}return 0;}
bool check2(int l,int r)
{
	int i,j,k,w;
	if(pl[l]&&l+pl[l]-1<=r||pr[r]&&r-pr[r]+1>=l) return 1; // follow way to calc border is wrong without this case  baaaaacccbaaaaa
	for(k=1;k+k<=r-l+1;k<<=1){
		long long tmp=gth(r-k+1,r);
		i=lower_bound(mp[k][tmp].begin(),mp[k][tmp].end(),l)-mp[k][tmp].begin();j=lower_bound(mp[k][tmp].begin(),mp[k][tmp].end(),r-k+1)-mp[k][tmp].begin();
		for(w=i;w<min(j,i+blk);++w){
			int len=k+mp[k][tmp][w]-l;
			if(2*len>r-l+1||len>k+k)break;
			if(gth(l,l+len-1)==gth(r-len+1,r))return 1;
		}
	}
	return 0;
}
bool check3(int l,int r)
{
	int k=lg[r-l+1];return min(mi[l][k],mi[r-(1<<k)+1][k])<=r;
}
int solve(int l,int r)
{
	if(check_bad(l,r)) return -1;
	if(check1(l,r)) return 1;
	if(qry(l+1,r,st[l]-'a')||qry(l,r-1,st[r]-'a')){
		if(check2(l,r)) return 2;
		return 3;
	}
	else{
		if(check3(l,r)) return 3;
		return 4;
	}
}
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	fz(i,2,200000) lg[i]=lg[i/2]+1;
	read(n);st=" ";fz0k(i,n){char c;while(!islower(c=getchar()));st.push_back(c);}read(q);
	pw1[0]=pw2[0]=1;
	fz1(i,n){
		pw1[i]=1ll*pw1[i-1]*e1%mod1;pw2[i]=1ll*pw2[i-1]*e2%mod2;hsh1[i]=(1ll*hsh1[i-1]*e1+st[i])%mod1;hsh2[i]=(1ll*hsh2[i-1]*e2+st[i])%mod2;
		memcpy(cnt[i],cnt[i-1],sizeof(cnt[i]));cnt[i][st[i]-'a']++;
	}
	fz(i,2,n)if(p[i].empty()) fz1(j,n/i) p[i*j].push_back(i);
	for(k=1;k<=n;k<<=1)for(i=1;i+k-1<=n;++i)mp[k][gth(i,i+k-1)].push_back(i);
	fz1(i,n){
		for(k=1;i+k-1<=n&&!pl[i];k<<=1){
			j=lower_bound(mp[k][gth(i,i+k-1)].begin(),mp[k][gth(i,i+k-1)].end(),i)-mp[k][gth(i,i+k-1)].begin()+1;
			for(;j<min((int)mp[k][gth(i,i+k-1)].size(),j+blk)&&mp[k][gth(i,i+k-1)][j]-i<=2*k&&!pl[i];++j){
				int len=mp[k][gth(i,i+k-1)][j]-i;if(i+len+len>=n)break;
				if(gth(i,i+len-1)==gth(i+len,i+len+len-1)) pl[i]=2*len;
			}
		}
	}
	fz1(i,n){
		for(k=1;i-k+1>=1&&!pr[i];k<<=1){
			j=lower_bound(mp[k][gth(i-k+1,i)].begin(),mp[k][gth(i-k+1,i)].end(),i-k+1)-mp[k][gth(i-k+1,i)].begin()-1;
			for(;j>max(-1,j-blk)&&i-k+1-mp[k][gth(i-k+1,i)][j]<=2*k&&!pr[i];--j){
				int len=i-k+1-mp[k][gth(i-k+1,i)][j];if(i-len-len<0)break;
				if(gth(i-len+1,i)==gth(i-len-len+1,i-len)) pr[i]=2*len;
			}
		}
	}
	for(i=1;i<=n;++i){if(pl[i])mi[i][0]=i-1+pl[i];else mi[i][0]=n+1;}
	fz1(i,18)fz1(j,n-(1<<i)+1) mi[j][i]=min(mi[j][i-1],mi[j+(1<<(i-1))][i-1]);
	while(q--){
		int l,r;read(l);read(r);
		printf("%d\n",solve(l,r));
	}
	return 0;
}