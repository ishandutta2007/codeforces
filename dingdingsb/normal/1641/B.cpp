// Problem: B. Repetitions Decoding
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=5e2+100;
int t,n,a[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		vector<int>now;
		vector<pair<int,int>>ans1;
		vector<int>ans2;
		map<int,int>cnt;
		int pos=1;//now.front
		for(int i=1,x;i<=n;i++)read(x),now.pb(x),cnt[x]++;
		for(auto kk:cnt)if(kk.se&1){
			puts("-1");
			goto loop;
		}
		while(now.size()){
			int i=1;
			while(now[i]!=now[0])i++;
			//now[i]=now[0]
			vector<int>tmp;
			for(int j=1;j<i;j++)tmp.pb(now[j]),ans1.pb(mp(pos+i+j-1,now[j]));
			reverse(tmp.begin(),tmp.end());pos+=2*i;ans2.pb(2*i);
			for(int j=i+1;j<now.size();j++)tmp.pb(now[j]);
			now.swap(tmp);
		}
		printf("%d\n",ans1.size());
		for(auto kk:ans1)printf("%d %d\n",kk.fi,kk.se);
		printf("%d\n",ans2.size());
		for(auto kk:ans2)printf("%d ",kk);pc('\n');
		loop:;
	}
}