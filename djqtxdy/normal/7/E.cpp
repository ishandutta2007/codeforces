#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
namespace Maxflow{
	const int Maxn=1005;
	struct edge{
		int to,rev,cap;
		edge(int _to,int _rev,int _cap){
			to=_to,rev=_rev,cap=_cap;
		}
	};
	int src=1002,snk=1003;
	vector<edge> G[Maxn];
	int dist[Maxn],seen[Maxn];
	int n;
	void Clear(){
		for (int i=0;i<Maxn;i++) G[i].clear();
	}
	void bfs(int s){
		for (int i=0;i<Maxn;i++) dist[i]=-1;
		dist[s]=0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int i=0;i<G[x].size();i++){
				edge &e=G[x][i];
				if (e.cap && dist[e.to]==-1){
					dist[e.to]=dist[x]+1;
					Q.push(e.to);
				}
			}
		}
	}
	int dfs(int now,int dest,int fl){
		if (now==dest) return fl;
		for (int &i=seen[now];i<G[now].size();i++){
			edge &ed=G[now][i];
			if (ed.cap && dist[ed.to]==dist[now]+1){
				int f=dfs(ed.to,dest,min(fl,ed.cap));
				if (f){
					ed.cap-=f;
					G[ed.to][ed.rev].cap+=f;
					return f;
				}
			}
		}
		return 0;
	}
	int dinic(int s=src,int t=snk){
		int ret=0;
		while (1){
			memset(seen,0,sizeof(seen));
			bfs(s);
			if (dist[t]==-1) return ret;
			int f=dfs(s,t,INF);
			while(f){
				ret+=f;
				f=dfs(s,t,INF);
			}
		}
	}
};
namespace Geometry{
	struct iP{
		LL x,y;
		iP(LL _x,LL _y){
			x=_x,y=_y;
		}
		iP(){
			x=y=0;
		}
		iP operator +(iP p){
			return iP(x+p.x,y+p.y);
		}
		iP operator -(iP p){
			return iP(x-p.x,y-p.y);
		}
		iP operator *(LL k){
			return iP(x*k,y*k);
		}
		LL det(iP p){
			return x*p.y-y*p.x;
		}
		LL dot(iP p){
			return x*p.x+y*p.y;
		}
		LL dist(){
			return x*x+y*y;
		}
		bool operator <(const iP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	struct dP{
		double x,y;
		dP(double _x,double _y){
			x=_x,y=_y;
		}
		dP(){
			x=y=0.0;
		}
		dP operator +(dP p){
			return dP(x+p.x,y+p.y);
		}
		dP operator -(dP p){
			return dP(x-p.x,y-p.y);
		}
		dP operator *(double k){
			return dP(x*k,y*k);
		}
		double det(dP p){
			return x*p.y-y*p.x;
		}
		double dot(dP p){
			return x*p.x+y*p.y;
		}
		double dist(){
			return x*x+y*y;
		}
		bool operator <(const dP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	vector<iP> convex_hull(iP X[],int l){
		#define sz ret.size()
		vector<iP> ret;
		sort(X+1,X+1+l);
		ret.pb(X[1]);
		for (int i=2;i<=l;i++){
			while (sz>=2 && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		int rs=ret.size()+1;
		for (int i=l-1;i>=1;i--){
			while (sz>=rs && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		return ret;
	}
};
struct expr{
	int tp;
	expr(int _tp=0){
		tp=_tp;
	}
	expr operator +(expr t){
		if(tp==-1 || t.tp==-1) return expr(-1);
		return expr(1);
	}
	expr operator -(expr t){
		if (tp==-1 || t.tp==-1){
			return expr(-1);
		}
		if (t.tp==1){
			return expr(-1);
		}
		return expr(1);
	}
	expr operator *(expr t){
		if (tp==-1 || tp==1 || t.tp==-1 || t.tp==1){
			return expr(-1);
		}
		return expr(2);
	}
	expr operator /(expr t){
		if (tp==-1 || tp==1 || t.tp==-1 || t.tp==1){
			return expr(-1);
		}
		if (t.tp==2) return expr(-1);
		return expr(2);
	}
	
	expr br(){
		if (tp==-1) return expr(-1);
		return expr(0);
	}
};
int n;
const int Maxn=105;
string s;
map<string,expr> M;
bool isal(char c){
	return (c>='0' &&c<='9') ||(c>='a' && c<='z')||(c>='A' && c<='Z');
}
string Cut(string &E){
	string ret;
	if (E[0]=='('){
		int tmp=0;
		for (int i=0;i<E.size();i++){
			ret+=E[i];
			if (E[i]=='(') tmp++;
			else if (E[i]==')') tmp--;
			if(tmp==0){
				if (i!=E.size()-1)E=E.substr(i+1); 
				else E="";
				return ret;
			}
		}
	}
	else{
		for (int i=0;i<E.size();i++){
			if (!isal(E[i])){
				E=E.substr(i);
				return ret;
			} 
			ret+=E[i];
		}
		E="";
		return ret; 
	}
	
} 
expr Get(string E){
	//cout<<E<<endl; 
	if (E.empty()) return expr(0);
	bool flag=true;
	for (int i=0;i<E.size();i++){
		if (!isal(E[i])) flag=false;
	}
	if (flag){
		if (!M.count(E)){
			M[E]=expr(0);
		}
		return M[E];
	}
	bool fg=(E[0]=='(');
	if (fg){
		int pos,ttt=0;
		for (pos=0;pos<E.size();pos++){
			if (E[pos]=='(')ttt++;
			else if (E[pos]==')')ttt--;
			if (ttt==0) break;
		}
		if (pos==E.size()-1){
			
		if (E.size()==2) return expr(1);
		return Get(E.substr(1,E.size()-2)).br();
		}
	}
	expr tt=expr(0);
	expr fi=Get(Cut(E));
	char P='&';
	while (1){
		if (E.empty()) break;
		char op=E[0];E=E.substr(1);
		expr nx=Get(Cut(E));
	//	cout<<op<<' '<<nx.tp<<' '<<tt.tp<<endl;
		if (op=='*') fi=fi*nx;
		else if (op=='/') fi=fi/nx;
		else if (op=='+' || op=='-'){
			if (P=='+' || P=='&') tt=tt+fi;
			else tt=tt-fi;
			P=op;
			fi=nx;
		}
		else{
			cout<<op<<endl;
			assert(false);
		}
	}
	if (P=='+') tt=tt+fi;
	else if (P=='-')tt=tt-fi;
	else return fi;
	return tt; 
}
void Fuck_space(string &E){
	string ret;
	for (int i=0;i<E.size();i++){
		if (E[i]!=' ') ret+=E[i];
	}
	E=ret;
}
string ff="#define";
int main(){
	cin>>n;
	getchar();
	for (int i=1;i<=n;i++){
		getline(cin,s);
		//s=s.substr(8);
		int j,p=0;
		for (j=0;j<s.size();j++){
			if (s[j]==ff[p]){
				p++;
			}
			if (p==ff.size()) break;
		}
		j++;
		for (;j<s.size();j++){
			if (s[j]!=' ') break;
		}
		s=s.substr(j);
		string nam;
		for (j=0;j<s.size();j++){
			if (s[j]==' ') break;
			nam+=s[j];
		}
		s=s.substr(j+1);
		Fuck_space(s);
		M[nam]=Get(s);
		//cout<<M[nam].tp<<endl;
	}
	getline(cin,s);
	Fuck_space(s);
//	cout<<s<<endl;
	expr tt=Get(s);
	if (tt.tp==-1){
		cout<<"Suspicious"<<endl;
	}
	else{
		cout<<"OK"<<endl;
	}
	return ~~(0^_^0);
}