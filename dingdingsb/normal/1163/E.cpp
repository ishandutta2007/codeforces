#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn_wei=30;
vector<int> w;
struct node{
	//
	int b[maxn_wei];
	void insert(int x){
		int tmp=x;
		for(int i=maxn_wei-1;i>=0;i--){
			if(!(x&(1<<i)))continue;
			if(!b[i]){
				b[i]=x;
				w.push_back(tmp);
				return ;
			}
			x^=b[i];
		}
	}
}Base;
const int maxn=2e7+100;
int n,s[maxn];
int ans[maxn],m;
inline void dfs(int dep){
	if(dep == -1) return;
	dfs(dep - 1); ans[++ m] = w[dep]; dfs(dep - 1);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(s[i]);
	sort(s+1,s+1+n);
	int k=0;
	for(int j=1,i=1;i<maxn_wei;i++){
		for(;j<=n&&s[j]<(1<<i);j++)Base.insert(s[j]);
		if(w.size()==i)k=i;
	}
	printf("%d\n",k);
	dfs(k);ans[0]=0;
	for(int i=0;i<(1<<k);i++){
		ans[i]^=ans[i-1];
		printf("%d ",ans[i]);
	}
}