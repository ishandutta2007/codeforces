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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int c[N],n,p,Cas;

void rmain(){
	read(n),Cas++;
	rep(i,1,n){
		read(p);
		p=(i+p%n+n)%n;
		if(p==0) p=n;
		c[p]=Cas;
	}
	int flag=0;
	rep(i,1,n){
		if(c[i]!=Cas) flag=1;
	}
	puts(flag?"NO":"YES");
}

int main(){
	int T; read(T);
	while(T--) rmain();

	return 0;
}