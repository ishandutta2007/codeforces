// Problem: CF891C Envy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF891C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N=5e5+100;
int n,m,q;
struct edge{
	int u,v,w;
	int U,V;
}e[N];
vector<int>id[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		read(e[i].u,e[i].v,e[i].w),id[e[i].w].pb(i);
	for(int W=1;W<=500000;W++){
		for(auto E:id[W])e[E].U=find(e[E].u),e[E].V=find(e[E].v);
		for(auto E:id[W])merge(e[E].u,e[E].v);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	read(q);while(q--){
		int k;read(k);
		vector<tuple<int,int,int>>v;
		for(int i=1;i<=k;i++){
			int a;read(a);
			v.pb(make_tuple(e[a].w,e[a].U,e[a].V));
		}
		sort(v.begin(),v.end());
		bool flag=1;
		for(int i=0;i<v.size()&&flag;){
			if(get<1>(v[i])==get<2>(v[i])){flag=0;break;}
			merge(get<1>(v[i]),get<2>(v[i]));
			int j=i+1;
			while(j<v.size()&&get<0>(v[j])==get<0>(v[i])){
				if(find(get<1>(v[j]))==find(get<2>(v[j]))){flag=0;break;}
				merge(get<1>(v[j]),get<2>(v[j]));j++;
			}
			while(i<j)fa[get<1>(v[i])]=get<1>(v[i]),fa[get<2>(v[i])]=get<2>(v[i]),i++;
		}
		if(flag)puts("YES");else puts("NO");
	}
}