// Problem: CF1553G Common Divisor Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1553G
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=3e5+10,K=1e6+10;
int n,q,a[N];
namespace MAtH{
	int mnp[K];
	void orz(){
		for(int i=2;i<K;i++){
			if(!mnp[i]){
				mnp[i]=i;
				for(int j=1;i*j<K;j++)
					if(!mnp[i*j])
						mnp[i*j]=i;
			}
		}
	}
	vector<int>fac(int x){
		vector<int>res;
		while(x>1){
			res.pb(mnp[x]);
			x/=mnp[x];
		}
		return res;
	}
}
using MAtH::fac;
set<pair<int,int>>S;
int fa[N];int rt[K];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	fa[x]=y;
}
signed main(){
	MAtH::orz();
	read(n,q);for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		read(a[i]);auto res=fac(a[i]);
		for(auto x:res)
			if(!rt[x])
				rt[x]=i;
			else
				merge(rt[x],i);
	}
	for(int i=1;i<=n;i++){
		auto res=fac(a[i]+1);
		for(auto x:res)
			if(rt[x])
				S.insert({find(i),find(rt[x])});
		for(auto x:res)for(auto y:res)
			if(rt[x]&&rt[y])
				S.insert({find(rt[x]),find(rt[y])});
	}
	
	while(q--){
		int s,t;read(s,t);
		if(find(s)==find(t))puts("0");
		else if(S.count({find(s),find(t)})||S.count({find(t),find(s)}))
			puts("1");
		else puts("2");
	}
}