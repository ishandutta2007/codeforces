#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n;
char s[100010],t[100010];

bool tag;
bool dir;
int a[100010]; int l,r;
int get_back(){
	if (dir) return a[l]^tag;
	return a[r]^tag;
}
int get_front(){
	if (dir) return a[r]^tag;
	return a[l]^tag;
}
void pop_back(){
	if (dir) ++l;
	else --r;
}
void work(){
	tag^=1,dir^=1;
}

void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	tag=dir=0;
	rep(i,1,n) a[i]=s[i]-'0';
	l=1,r=n;
	vector<int> S;
	per(i,1,n){
		if (get_back()==t[i]-'0') pop_back();
		else{
			if (get_front()!=t[i]-'0') S.pb(i),work();
			else S.pb(1),S.pb(i),work();
			pop_back();
		}
	}
	printf("%d",int(S.size()));
	for (int x: S) printf(" %d",x);
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}