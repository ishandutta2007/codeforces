#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=55;
int a[N],n,q;
vi x[N];

void operate(vi &x){
	vi nw;
	for(auto t:x){
		if(t) nw.pb(t);
	}
	x=nw;
	vector<vi> D;
	int cur=1;
	for(auto len:x){
		vi tmp;
		rep(j,1,len){
			tmp.pb(a[cur++]);
		}
		D.pb(tmp);
	}
	reverse(ALL(D));
	cur=1;
	for(auto x:D){
		for(auto y:x){
			a[cur++]=y;
		}
	}
}

int main(){
	read(n);
	rep(i,1,n) read(a[i]);
	for(int len=0;len*2+2<=n;len++){
		int A=len+1,B=n-len,pA=0,pB=0;
		rep(i,1,n){
			if(A==a[i]) pA=i;
			if(B==a[i]) pB=i;
		}
		vi opt;
		if(pA<=pB){
			opt.pb(len);
			opt.pb(pA-len);
			opt.pb(n-len-pA);
			opt.pb(len);
		}
		else{
			opt.pb(len);
			opt.pb(n-len-len);
			opt.pb(len);
		}
		x[++q]=opt;
		operate(x[q]);
		if(SZ(x[q])==1) q--;
		pA=pB=0;
		rep(i,1,n){
			if(A==a[i]) pA=i;
			if(B==a[i]) pB=i;
		}
		assert(pB<=pA);
		opt.clear();
		opt.pb(len);
		opt.pb(pB-len);
		opt.pb(pA-pB-1);
		opt.pb(n-len-pA+1);
		opt.pb(len);
		x[++q]=opt;
		operate(x[q]);
		if(SZ(x[q])==1) q--;
	}
	printf("%d\n",q);
	rep(i,1,q){
		printf("%d",SZ(x[i]));
		for(auto t:x[i]) printf(" %d",t);
		puts("");
	}
	return 0;
}