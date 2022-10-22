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
const int N=1e5+100;
int n,m1,m2;
struct DSU{
	int fa[N];
	DSU(){for(int i=1;i<N;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		x=find(x),y=find(y);
		fa[x]=y;
	}
}A,B;
signed main(){
	read(n,m1,m2);
	for(int i=1,u,v;i<=m1;i++)
		read(u,v),A.merge(u,v);
	for(int i=1,u,v;i<=m2;i++)
		read(u,v),B.merge(u,v);
	vector<pair<int,int>>ans;vector<int>L,R;
	for(int i=1;i<=n;i++)if(A.find(i)!=A.find(1)&&B.find(i)!=B.find(1))
		A.merge(1,i),B.merge(1,i),ans.pb(mp(1,i));
	for(int i=1;i<=n;i++)
		if(A.find(i)!=A.find(1))A.merge(1,i),L.pb(i);
		else if(B.find(i)!=B.find(1))B.merge(1,i),R.pb(i);
	write(ans.size()+min(L.size(),R.size()));putchar('\n');
	for(auto E:ans)write(E.first),putchar(' '),write(E.second),putchar('\n');
	for(int i=0;i<L.size()&&i<R.size();i++)write(L[i]),putchar(' '),write(R[i]),putchar('\n');
}