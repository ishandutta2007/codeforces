// Problem: CF1103D Professional layer
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1103D
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
const int N=1e6+7;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
#define fi first
#define se second
int n,m,k,res,f[12][1<<11],g[1<<11];
map<int,vector<int>>mp;
struct node{
	int a,w;bool operator<(const node a)const{
		return w<a.w;
	}
}c[N];
vector<int>fac;
int b[1<<11];
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++)
		read(c[i].a),res=gcd(res,c[i].a);
	for(int i=1;i<=n;i++)read(c[i].w);
	if(res==1)return puts("0"),0;
	for(int i=2;i<=1e6&&i*i<=res;i++){
		if(res%i)continue;
		fac.push_back(i);
		while(res%i==0)res/=i;
	}
	if(res>1)fac.push_back(res);
	m=fac.size();
	for(int i=1;i<=n;i++){
		int z=1;
		for(auto j:fac)while(c[i].a%j==0)c[i].a/=j,z*=j;
		mp[z].push_back(c[i].w);
	}
	memset(f,0x02,sizeof f);
	f[0][0]=0;
	for(auto t:mp){
		int x=t.fi;
		sort(t.se.begin(),t.se.end());
		if(t.se.size()>m)t.se.resize(m);
		for(int S=0;S<1<<m;S++){
			int times=1,p=x;
			for(int j=0;j<m;j++)if(S>>j&1)
				while(p%fac[j]==0)p/=fac[j],times*=fac[j];
			b[S]=times;
		}
		for(auto p:t.se){
			for(int i=m-1;~i;i--)
				for(int S=0;S<1<<m;S++)if(f[i][S]<1e12){
					int tmp=(1<<m)-1-S;
					for(int k=tmp;k;k=(k-1)&tmp)
						if(b[k]<=::k)
							if(f[i+1][S|k]>f[i][S]+p)
								f[i+1][S|k]=f[i][S]+p;
				}
		}
	}
	int ans=1e18;
	for(int i=1;i<=m;i++)ans=min(ans,f[i][(1<<m)-1]*i);
	if(ans>1e12)puts("-1");
	else write(ans);
}