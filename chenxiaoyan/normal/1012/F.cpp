/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=22;
const int inf=0x3f3f3f3f;
int n,p;
int s[N+1],len[N+1],t[N+1];
int ord_s[N+1],ord_t[N+1];
bool cmp_s(int x,int y){return s[x]<s[y];}
bool cmp_t(int x,int y){return t[x]<t[y];}
int dp[1<<N],pa[1<<N];
int ans1[N+1],ans2[N+1];
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++)cin>>s[i]>>len[i]>>t[i],ord_s[i]=ord_t[i]=i;
	sort(ord_s+1,ord_s+n+1,cmp_s);sort(ord_t+1,ord_t+n+1,cmp_t);
	memset(dp,0x3f,sizeof(dp));dp[0]=1;
	for(int i=0;i<1<<n;i++){
//		printf("dp[%d]=%d\n",i,dp[i]);
		if(dp[i]==inf)continue;
		int st=dp[i],now=0;
		for(int j=n;j;j--)if(st>s[ord_s[j]]+len[ord_s[j]]-1){now=j;break;}
		for(int j=1;j<=n;j++)if(!(i&1<<ord_t[j]-1)){
			while(now+1<=n&&(s[ord_s[now+1]]<=st&&st<=s[ord_s[now+1]]+len[ord_s[now+1]]-1||st+t[ord_t[j]]>=s[ord_s[now+1]])){
				now++;
				if(s[ord_s[now]]<=st&&st<=s[ord_s[now]]+len[ord_s[now]]-1||i&1<<ord_s[now]-1&&st+t[ord_t[j]]>=s[ord_s[now]])
					st=s[ord_s[now]]+len[ord_s[now]];
			}
			if(st+t[ord_t[j]]<s[ord_t[j]]&&st+t[ord_t[j]]<dp[i|1<<ord_t[j]-1])dp[i|1<<ord_t[j]-1]=st+t[ord_t[j]],pa[i|1<<ord_t[j]-1]=ord_t[j];
		}
	}
	if(p==1){
		if(dp[(1<<n)-1]==inf)return puts("NO"),0;
		puts("YES");
		int now=(1<<n)-1;
		while(now){
			ans1[pa[now]]=1,ans2[pa[now]]=dp[now]-t[pa[now]];
			now^=1<<pa[now]-1;
		}
	}
	else{
		for(int i=0;i<1<<n;i++){
			if(dp[i]==inf||dp[(1<<n)-1^i]==inf)continue;
			puts("YES");
			int now=i;
			while(now){
				ans1[pa[now]]=1,ans2[pa[now]]=dp[now]-t[pa[now]];
				now^=1<<pa[now]-1;
			}
			now=(1<<n)-1^i;
			while(now){
				ans1[pa[now]]=2,ans2[pa[now]]=dp[now]-t[pa[now]];
				now^=1<<pa[now]-1;
			}
			break;
		}
		if(!ans1[1])return puts("NO"),0;
	}
	for(int i=1;i<=n;i++)cout<<ans1[i]<<" "<<ans2[i]<<"\n";
	return 0;
}
/*1
2 1
3 1 1
6 1 1
*/
/*2
3 1
13 2 2
7 3 1
19 3 4
*/
/*3
7 2
15 1 1
14 1 1
18 1 1
21 1 1
9 4 6
22 2 5
5 4 3
*/
/*4
16 2
29 1 10
30 1 7
31 1 13
67 1 14
68 1 4
69 1 6
70 1 3
71 1 31
72 1 8
73 1 5
74 1 6
75 1 5
76 1 8
91 1 13
92 1 4
93 1 15
*/