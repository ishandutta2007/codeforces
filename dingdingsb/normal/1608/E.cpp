// Problem: E. The Cells on the Paper
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.ml/contest/1608/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int N=1e5+10;
int n,x[N],y[N],c[N];
vector<int>X,Y;
struct Solver{
	int x[N],y[N],c[N];
	vector<int>id[N][4];int pres[N];int cnt[N][4];bool tmp;
	bool chk(int k){
		//3
		//---
		//2
		memset(cnt,0,sizeof cnt);
		int up=Y.size(),pre=0;
		int down=1,suf=0;
		for(int i=X.size();i;i--){
			for(auto p:id[i][2])if(y[p]<=up)pre++,cnt[y[p]][2]++;
			for(auto p:id[i][3])if(y[p]>=down)suf++,cnt[y[p]][3]++;
			while(pre-cnt[up][2]>=k)pre-=cnt[up][2],up--;
			while(suf-cnt[down][3]>=k)suf-=cnt[down][3],down++;
			if(pre>=k&&suf>=k&&up<down&&pres[i-1]>=k)return 1;
		}
		if(tmp){
			int a=0,b=X.size()+1,sum=0;
			while(a<(int)X.size()&&sum<k)a++,sum+=id[a][1].size();
			if(sum<k)return 0;
			sum=0;
			while(b>1&&sum<k)b--,sum+=id[b][2].size();
			if(sum<k)return 0;
			if(a>b)return 0;
			sum=0;
			for(int i=a+1;i<b;i++)
				sum+=id[i][3].size();
			return sum>=k;
		}else return 0;
	}
	int work(bool kk){
		tmp=kk;
		for(int i=1;i<=(int)X.size();i++)
			id[i][1].clear(),id[i][2].clear(),id[i][3].clear();
		for(int i=1;i<=n;i++)id[x[i]][c[i]].pb(i);
		for(int i=1;i<=(int)X.size();i++)pres[i]=pres[i-1]+id[i][1].size();
		int l=1,r=n/3,ans=0;
		while(l<=r){
			if(chk(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		return ans;
	}
}kk;
int trans[6][3]={
	{1,2,3},
	{1,3,2},
	{2,1,3},
	{2,3,1},
	{3,1,2},
	{3,2,1}
};
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(x[i],y[i],c[i]),X.pb(x[i]),Y.pb(y[i]);
	sort(X.begin(),X.end());
	X.resize(unique(X.begin(),X.end())-X.begin());
	sort(Y.begin(),Y.end());
	Y.resize(unique(Y.begin(),Y.end())-Y.begin());
	for(int i=1;i<=n;i++)x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin()+1;
	for(int i=1;i<=n;i++)y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin()+1;
	int ans=0,cnt=0;
	for(int T=0;T<6;T++){
		{
			++cnt;
			for(int i=1;i<=n;i++)
				kk.x[i]=x[i],
				kk.y[i]=y[i],
				kk.c[i]=trans[T][c[i]-1];
			chkmx(ans,kk.work(1));
		}
		{
			++cnt;
			for(int i=1;i<=n;i++)
				kk.x[i]=X.size()+1-x[i],
				kk.y[i]=y[i],
				kk.c[i]=trans[T][c[i]-1];
			chkmx(ans,kk.work(0));
		}
	}
	swap(X,Y);
	for(int i=1;i<=n;i++)swap(x[i],y[i]);
	for(int T=0;T<6;T++){
		{
			++cnt;
			for(int i=1;i<=n;i++)
				kk.x[i]=x[i],
				kk.y[i]=y[i],
				kk.c[i]=trans[T][c[i]-1];
			chkmx(ans,kk.work(1));
		}
		{
			++cnt;
			for(int i=1;i<=n;i++)
				kk.x[i]=X.size()+1-x[i],
				kk.y[i]=y[i],
				kk.c[i]=trans[T][c[i]-1];
			chkmx(ans,kk.work(0));
		}
	}
	write(ans*3);
}