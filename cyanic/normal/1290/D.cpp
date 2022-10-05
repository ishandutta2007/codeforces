#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=10006;
int f[N],n,K;

void reset(){
	cout<<"R"<<endl;
}

int ask(int x){
	cout<<"? "<<x+1<<endl;
	string s; cin>>s;
	return s[0]=='Y';
}

int main(){
	cin>>n>>K;
	if(K==1){
		REP(i,n) rep(j,i+1,n-1)
			reset(),ask(i),f[j]|=ask(j);
	}
	else{
		int b=K/2,m=n/b;
		rep(d,1,m) REP(s,d) if(s+d<m){
			reset();
			for(int i=s;i<m;i+=d)
				rep(x,i*b,(i+1)*b-1) f[x]|=ask(x);
		}
	}
	cout<<"! "<<n-accumulate(f,f+n,0)<<endl;
	return 0;
}