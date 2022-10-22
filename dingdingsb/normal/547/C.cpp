//#pragma optimize(2)
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
const int maxn=5e5+10;
bool isprime[maxn];
int tot,prime[maxn],miu[maxn];
vector<int>factor[maxn];
void init(){
	tot=0;miu[1]=1;memset(isprime,0xff,sizeof isprime);
	for(int i=2;i<maxn;i++){
		if(isprime[i])
			prime[++tot]=i,miu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<maxn;j++){
			isprime[i*prime[j]]=false;
			if(i%prime[j])miu[i*prime[j]]=-miu[i];
			else {miu[i*prime[j]]=0;break;}
		}
	}
	for(int i=1;i<maxn;i++)
		for(int j=i;j<maxn;j+=i)factor[j].push_back(i);
}
int n,q;
bool flag[maxn];
int a[maxn],c[maxn];
long long f[maxn];
long long ans=0;
void change(int x,int v){
	for(int i=0;i<factor[x].size();i++){
		ans-=1ll*miu[factor[x][i]]*f[factor[x][i]]*f[factor[x][i]];
		f[factor[x][i]]+=v;
		ans+=1ll*miu[factor[x][i]]*f[factor[x][i]]*f[factor[x][i]];
	}
}
signed main(){
	init();
	read(n,q);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=q;i++){
		int x;read(x);
		if(flag[x])c[a[x]]--,change(a[x],-1),flag[x]=false;
		else if(!flag[x])c[a[x]]++,change(a[x],1),flag[x]=true;
		write((ans-c[1])/2);putchar('\n'); 
	}
	return 0;
}