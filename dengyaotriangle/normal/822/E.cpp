#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;
const int maxl=20;

int n,m,t;
char s[maxn];
int sa[maxn],rnk[maxn],pre[maxn<<1],cnt[maxn],h[maxn];
int st[maxl][maxn];
int lg2[maxn];

int dp[maxn];

int lcp(int x,int y){//s[x...n]&&t[y...m]
	if(x>n||y>m)return 0;
	x=rnk[x],y=rnk[y+n+1];
	if(x>y)swap(x,y);
	x++;
	int lg=lg2[y-x+1];
	return min(st[lg][x],st[lg][y-(1<<lg)+1]);
}
int main(){
	lg2[1]=0;for(int i=2;i<maxn;i++)lg2[i]=lg2[i>>1]+1;
	scanf("%d%s",&n,s+1);
	s[n+1]='#';
	scanf("%d%s",&m,s+2+n);
	t=n+m+1;
	for(int i=1;i<=t;i++)cnt[s[i]]++;
	for(int i=1;i<256;i++)cnt[i]+=cnt[i-1];
	for(int i=t;i>=1;i--)sa[cnt[s[i]]--]=i;
	rnk[sa[1]]=1;for(int i=2;i<=t;i++)rnk[sa[i]]=rnk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	int c=rnk[sa[t]];
	for(int k=1;k<t&&c<t;k<<=1){
		int g=0;
		for(int i=1;i<=t;i++)if(sa[i]-k>0)pre[++g]=sa[i]-k;
		for(int i=t-k+1;i<=t;i++)pre[++g]=i;
		for(int i=1;i<=c;i++)cnt[i]=0;
		for(int i=1;i<=t;i++)cnt[rnk[i]]++;
		for(int i=1;i<=c;i++)cnt[i]+=cnt[i-1];
		for(int i=t;i>=1;i--)sa[cnt[rnk[pre[i]]]--]=pre[i];
		for(int i=1;i<=t;i++)pre[i]=rnk[i];
		rnk[sa[1]]=1;
		for(int i=2;i<=t;i++)rnk[sa[i]]=rnk[sa[i-1]]+(pre[sa[i]]!=pre[sa[i-1]]||pre[sa[i]+k]!=pre[sa[i-1]+k]);
		c=rnk[sa[t]];	
	}
	for(int i=1;i<=t;i++){
		if(rnk[i]==1)h[1]=0;
		else{
			int ch=h[rnk[i-1]];ch-=!!ch;
			while(s[i+ch]==s[sa[rnk[i]-1]+ch])ch++;
			h[rnk[i]]=ch;
		}
	} 
	for(int i=1;i<=t;i++)st[0][i]=h[i];
	for(int j=1;j<maxl;j++)for(int k=1;k<=t-(1<<j)+1;k++){
		st[j][k]=min(st[j-1][k],st[j-1][k+(1<<j>>1)]);
	}
	int q;scanf("%d",&q);
	for(int i=0;i<q;i++){
		for(int i=n;i>=1;i--){
			int s=lcp(i,dp[i-1]+1);
			dp[i+s-1]=max(dp[i+s-1],dp[i-1]+s);
		}
		for(int i=1;i<=n;i++)dp[i]=max(dp[i],dp[i-1]);
	}
	if(dp[n]==m)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}