#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
void get(string &s){
	static char t[1000010];
	scanf("%s",t+1); s=t+1;
}

int n,m,q,lim;
string S,T;
int sum[100010][26];

int nxt[1000010];
int getsum(const string &S,const string &T){  //how many S in T
	//printf("  test getsum %s %s\n",S.c_str(),T.c_str());
	nxt[0]=-1;
	for (int i=1,j;i<int(S.size());i++){
		for (j=nxt[i-1];~j&&S[j+1]!=S[i];j=nxt[j]);
		if (S[j+1]==S[i]) nxt[i]=j+1;
		else nxt[i]=-1;
	}
	int res=0;
	for (int i=0,j=-1;i<int(T.size());i++){
		for (;~j&&S[j+1]!=T[i];j=nxt[j]);
		if (S[j+1]==T[i]) j++;
		if (j+1==int(S.size())) res++,j=nxt[j];
	}
	return res;
}

int work(){
	int tim=read(); lim=qpow(2,tim);
	string R; get(R);
	string E=S; int p=0;
	while (p<tim&&E.size()<R.size()) E=E+T[p++]+E;
	if (E.size()<R.size()) return 0;
	int ans=0;
	add(ans,1LL*getsum(R,E)*qpow(2,tim-p)%mod);
	string F,G;
	for (int i=1;i<int(R.size());i++) F+=E[E.size()-R.size()+i],G+=E[i-1];
	for (int i=0;i<26;i++){
		int t=sum[tim][i];
		iadd(t,sum[p][i]);
		if (!t) continue;
		add(ans,1LL*getsum(R,F+char('a'+i)+G)*lim%mod*t%mod);
	}
	return ans;
}

void solve(){
	n=read(),q=read();
	get(S),get(T);
	for (int i=1;i<=n;i++){
		memcpy(sum[i],sum[i-1],sizeof sum[i]);
		add(sum[i][T[i-1]-'a'],qpow(2,mod-1-i));
	}
	m=S.size();
	while (q--) printf("%d\n",work());
}
int main()
{
	for (int T=1;T--;) solve();
}