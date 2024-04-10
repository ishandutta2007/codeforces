// Problem: CF1225G To Make 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1225G
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=16,M=2e3+1;
int n,k,a[N],b[N],sum;
bitset<M>dp[1<<N];
void get(int S,int x){
	if(!S)return;
	if(x*k<=sum&&dp[S][x*k]){
		for(int i=0;i<n;i++)if(S>>i&1)b[i]++;
		return get(S,x*k);
	}
	for(int i=0;i<n;i++)if((S>>i&1)&&x-a[i]>=0&&dp[S^1<<i][x-a[i]])
		return get(S^1<<i,x-a[i]);
}
signed main(){
	read(n,k);
	for(int i=0;i<n;i++)
		read(a[i]),sum+=a[i];
	dp[0][0]=1;
	for(int S=1;S<(1<<n);S++){
		for(int i=0;i<n;i++)if(S>>i&1)dp[S]|=dp[S^(1<<i)]<<a[i];
		for(int i=sum/k;i;i--)if(dp[S][i*k])dp[S][i]=1;
	}
	if(!dp[(1<<n)-1][1])return puts("NO"),0;
	puts("YES");
	get((1<<n)-1,1);
	priority_queue<pair<int,int>>q;
	for(int i=0;i<n;i++)q.push({b[i],a[i]});
	while(q.size()>1){
		auto x=q.top();q.pop();
		auto y=q.top();q.pop();
		assert(x.first==y.first);
		write(x.second);putchar(' ');
		write(y.second);putchar('\n');
		pair<int,int>c={x.first,x.second+y.second};
		while(c.second%k==0)c.second/=k,c.first--;
		q.push(c);
	}
	assert(q.top().second==1);
}