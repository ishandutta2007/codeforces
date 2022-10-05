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

void rmain(){
	vi a; int n,s=0,x;
	read(n);
	rep(i,1,n){
		read(x);
		s+=x;
		a.pb(x);
	}
	if(!s){
		puts("NO");
		return;
	}
	sort(ALL(a));
	if(s>0){
		reverse(ALL(a));
	}
	puts("YES");
	for(auto x:a){
		printf("%d ",x);
	}
	puts("");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();

	return 0;
}