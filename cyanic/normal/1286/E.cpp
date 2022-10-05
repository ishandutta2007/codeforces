#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const ll MASK=(1ll<<30)-1,inf=1e18;
const int N=600005;
int mn[N][20],lg[N],fa[N],anc[N],n,w;
ll res,ans2,ans,a26,a30;
map<int,int> cnt;
char s[N]; 
 
int qry(int l,int r){
	if(l>r) swap(l,r); else; int t=lg[r-l+1];
	return min(mn[r][t],mn[l+(1<<t)-1][t]);
}
 
int main(){
	read(n),lg[0]=-1,fa[0]=-1;
	rep(i,1,n) lg[i]=lg[i>>1]+1;
	rep(i,1,n){
		scanf("%s%d",s+i,&w);
		s[i]='a'+((s[i]-'a'+a26)%26);
		w^=(a30&MASK),mn[i][0]=w;
		rep(j,1,19) if(i>=(1<<j))
			mn[i][j]=min(mn[i-(1<<(j-1))][j-1],mn[i][j-1]);
		int p=fa[i-1];
		for(;p>=0&&s[p+1]!=s[i];p=fa[p]);
		fa[i]=p+1;
		if(s[i]==s[fa[i-1]+1]) anc[i-1]=anc[fa[i-1]];
		else anc[i-1]=fa[i-1];
		for(int p=i-1;p>=1;){
			if(s[p+1]==s[i]) p=anc[p];
			else{
				int tmp=qry(i-p,i-1);
				res-=tmp,cnt[tmp]--;
				p=fa[p];
			}
		}
		int tot=(s[i]==s[1]);
		while(!cnt.empty()&&cnt.rbegin()->fi>w){
			tot+=cnt.rbegin()->se;
			res-=(ll)cnt.rbegin()->fi*cnt.rbegin()->se;
			cnt.erase(--cnt.end());
		}
		res+=(ll)tot*w;
		cnt[w]+=tot;
		a26=(a26+res)%26;
		a30=(a30+res)&MASK;
		ans+=res;
		if(ans>=inf) ans2++,ans-=inf;
		if(ans2){
			printf("%lld",ans2);
			ll t=inf/10;
			while(ans<t&&t>=10) putchar('0'),t/=10;
			printf("%lld\n",ans);
		}
		else printf("%lld\n",ans);
	}
	return 0;
}