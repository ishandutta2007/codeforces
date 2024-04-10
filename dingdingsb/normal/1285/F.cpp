// Problem: CF1285F Classical?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1285F
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
int n,a[N],vis[N];
int tot,pr[N];bool npr[N];
int miu[N];vector<int>factor[N];
void init(){
	miu[1]=1;
	for(int i=2;i<N;i++){
		if(!npr[i])
			pr[++tot]=i,miu[i]=-1;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]){
				miu[i*pr[j]]=-miu[i];
			}else{
				miu[i*pr[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<N;i++)
		for(int j=1;i*j<N;j++)
			factor[i*j].push_back(i);
}
int cnt[N];
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
vector<int>fac;
void upd(int x,int op){
	for(auto d:factor[x])
		cnt[d]+=op;
}
signed main(){
	init();int lim=0;
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]),vis[a[i]]++,lim=max(lim,a[i]);
	long long ans=0;
	for(int g=1;g<=lim;g++){
		vector<int>b;
		for(int i=g;i<=lim;i+=g)for(int j=1;j<=vis[i];j++)
			b.push_back(i/g);
		stack<int>s;
		reverse(b.begin(),b.end());
		for(auto x:b){
			int c=0;
			for(auto d:factor[x])
				c+=miu[d]*cnt[d];
			while(c){
				int y=s.top();s.pop();
				upd(y,-1);
				if(gcd(x,y)==1)c--,ans=max(ans,1ll*x*y*g);
			}
			s.push(x);upd(x,1);
		}
		while(s.size())
			upd(s.top(),-1),s.pop();
	}
	write(ans);
}