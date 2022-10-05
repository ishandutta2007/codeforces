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

void rmain(){
	int n,x;
	vi a,b;
	read(n);
	rep(i,1,n){
		read(x);
		a.pb(x);
	}
	rep(i,1,n){
		read(x);
		b.pb(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(auto x:a) printf("%d ",x);
	puts("");
	for(auto x:b) printf("%d ",x);
	puts("");
}

int main(){
	int T;
	read(T);
	while(T--) rmain();

	return 0;
}