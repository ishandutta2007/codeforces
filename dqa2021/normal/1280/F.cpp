#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch)&&ch!='E';ch=G) if (ch=='-') flg=true;
	if (ch=='E') return -1;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<char,string> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int k,m,n;
int w[2][32];
int LP,LN,RP,RN,P,N,gnd[6],O;

void solve(){
	k=read(); m=k<<1|1,n=m*2-1;
	int px=-1,py=-1;
	rep(e,0,1) rep(i,1,k<<1|1){
		int &x=w[e][i]=read();
		if (!~x) px=e,py=i;
		else if (x>2*k+1) x=4*k+2-x+2*k+1;
	}
	//rep(e,0,1) rep(i,1,k<<1|1) printf("%d%c",w[e][i]," \n"[i==k*2+1]);
	static int p[64]; int q=0;
	
	rep(i,1,m) if (~w[0][i]) p[++q]=w[0][i];
	per(i,1,m) if (~w[1][i]) p[++q]=w[1][i];
	bool g=0;
	rep(i,1,q) rep(j,i+1,q) g^=p[i]>p[j];
	if (g) return puts("SURGERY FAILED"),void();
	puts("SURGERY COMPLETE");
	
	vector<string> S; string T;
	while (py>k+1) T+='l',swap(w[px][py],w[px][py-1]),--py;
	while (py<k+1) T+='r',swap(w[px][py],w[px][py+1]),++py;
	if (!px) T+='d',swap(w[px][py],w[px+1][py]),++px;
	
	q=0;
	rep(i,1,m) if (~w[0][i]) p[++q]=w[0][i];
	per(i,1,m) if (~w[1][i]) p[++q]=w[1][i];
	
	{
	string s;
	rep(_,1,k) s+='l';
	s+='u';
	rep(_,1,k) s+='r';
	s+='d';
	LN=S.size(); S.pb(s);
	}
	
	{
	string s;
	s+='u';
	rep(_,1,k) s+='l';
	s+='d';
	rep(_,1,k) s+='r';
	LP=S.size(); S.pb(s);
	}
	
	{
	string s;
	s+='u';
	rep(_,1,k) s+='r';
	s+='d';
	rep(_,1,k) s+='l';
	RN=S.size(); S.pb(s);
	}
	
	{
	string s;
	rep(_,1,k) s+='r';
	s+='u';
	rep(_,1,k) s+='l';
	s+='d';
	RP=S.size(); S.pb(s);
	}
	
	{
	string s;
	rep(_,1,k) s+='l';
	s+='u';
	rep(_,1,k<<1) s+='r';
	s+='d';
	rep(_,1,k) s+='l';
	N=S.size(); S.pb(s);
	}
	
	{
	string s;
	rep(_,1,k) s+='r';
	s+='u';
	rep(_,1,k<<1) s+='l';
	s+='d';
	rep(_,1,k) s+='r';
	P=S.size(); S.pb(s);
	}
	
	gnd[0]=P;
	rep(j,1,5){
		gnd[j]=S.size();
		const char c=gnd[j-1]+'A';
		string s; s+=c; s=s+s;
		S.pb(s);
	}
	
	{
	string s;
	s+=LP+'A';
	s+=RN+'A';
	s+=LN+'A';
	s+=RP+'A';
	O=S.size(); S.pb(s);
	}
	
	int pos=k+1;
	const auto rotate=[&](int p){
		int q=p;
		if (p>pos) p-=n;
		p=pos-p;
		//printf("rotate %d\n",p);
		rep(_,0,5) if (p>>_&1) T+=gnd[_]+'A';
		pos=q;
	};
	
	rep(i,1,n-2){
		int j=-1;
		rep(_,i,n) if (p[_]==i){j=_;break;}
		assert(~j);
		while (j-i>=2){
			rotate(j-1);
			T+=O+'A';
			swap(p[j],p[j-1]),swap(p[j-1],p[j-2]),j-=2;
		}
		if (j-i==1){
			//assert(j<n);
			rotate(j);
			T+=O+'A';
			swap(p[j+1],p[j]),swap(p[j],p[j-1]);
			T+=O+'A';
			swap(p[j+1],p[j]),swap(p[j],p[j-1]);
		}
	}
	rotate(k+1);
	
	rep(_,1,k) T+='r';
	puts(T.c_str());
	rep(i,0,S.size()-1) printf("%c %s\n",i+'A',S[i].c_str());
	puts("DONE");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}