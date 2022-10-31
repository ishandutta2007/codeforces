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
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
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
const int Maxn=266;
struct state{
	vector<int> A;
	vector<pair<int,pair<int,int> > > op; 
	state(){
		A.clear();op.clear();
	}
	//ky+x
};
bool c[Maxn];
void Out(state st){
	printf("%d\n",(int)st.op.size());
	for (int i=0;i<st.op.size();i++){
		pair<int,pair<int,int> > P=st.op[i];
		printf("lea e%cx, ",(char)(i+'a'+1));
		if (P.second.first==-1){
			printf("[%d*e%cx]\n",P.first,(char)(P.second.second+'a'));
		}
		else{
			printf("[e%cx + %d*e%cx]\n",(char)(P.second.first+'a'),P.first,(char)(P.second.second+'a'));
		}
	}
	exit(0);
}
int main(){
	int n;
	cin>>n;
	if (n==1){
		printf("0\n");
		return 0;
	}
	vector<state> now,nw;
	state tmp;
	tmp.A.pb(1);
	now.pb(tmp);
	int t=0;
	while (1){
		for (int ii=0;ii<now.size();ii++){
			vector<int> t=now[ii].A;
			memset(c,false,sizeof(c));
			for (int i=0;i<t.size();i++){
				if (t[i]*2<=n && !c[t[i]*2]){
					c[t[i]*2]=true;
					state xx;
					xx=now[ii];
					xx.A.pb(t[i]*2);
					xx.op.pb(mp(2,mp(-1,i)));
					if (t[i]*2==n) Out(xx);
					nw.pb(xx);
				}
				if (t[i]*4<=n && !c[t[i]*4]){
					c[t[i]*4]=true;
					state xx;
					xx=now[ii];
					xx.A.pb(t[i]*4);
					xx.op.pb(mp(4,mp(-1,i)));
					if (t[i]*4==n) Out(xx);
					nw.pb(xx);
				}
				if (t[i]*8<=n && !c[t[i]*8]){
					c[t[i]*8]=true;
					state xx;
					xx=now[ii];
					xx.A.pb(t[i]*8);
					xx.op.pb(mp(8,mp(-1,i)));
					if (t[i]*8==n) Out(xx);
					nw.pb(xx);
				}
			}
			for (int i=0;i<t.size();i++){
				for (int j=0;j<t.size();j++){
					for (int k=1;k<=8;k*=2){
						//i+kj
						int v=t[i]+k*t[j];
						if (v<=n && !c[v]){
							c[v]=true;
							state xx;
							xx=now[ii];
							xx.A.pb(v);
							xx.op.pb(mp(k,mp(i,j)));
							if (v==n) Out(xx);
							nw.pb(xx); 
						}
					}
				}
			}
		}
		now=nw;
		nw.clear();
	}
	return 0;
}