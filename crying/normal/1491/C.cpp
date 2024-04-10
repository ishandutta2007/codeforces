#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=5010,MAXM=2.5e7+10;
int T,n,s[MAXN],tot,flag;
ll ans,cnt[MAXN],now;
struct Node{
	int l,r;
}node[MAXM];
int main(){
	scanf("%d",&T);
	while(T--){
		tot=0,ans=0,flag=1;
		scanf("%d",&n);
		rep(i,1,n)cnt[i]=0,scanf("%d",&s[i]);
		rep(i,1,n)if(s[i]>1)flag=0;
		if(flag){printf("0\n");continue;}
		rep(i,1,n){
			if(i+s[i]>n){
				cnt[i]+=(i+s[i]-n);
				if(i==n)cnt[i]--;
			} 
			ans+=cnt[i];
		}
		per(i,n,1){
			per(j,i-2,1){
				if(j+s[j]>=i){
					node[++tot]=(Node){j,i};
				}
			}
		}
		now=n;
		rep(i,1,tot){
			int flag=0;
			while(now>=node[i].r){
				if(cnt[now]){
					cnt[now]--;cnt[node[i].l]++;
					flag=1;break;
				} 
				now--;
			}
			if(!flag){
				ans++;cnt[node[i].l]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}