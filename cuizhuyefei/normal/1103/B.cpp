#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}

bool query(int x, int y){
	printf("? %d %d\n",x,y);fflush(stdout);
	char t[3];scanf("%s",t);
	return t[0]=='x';
}
vector<int> getfac(int x){
	vector<int>res;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		int j=0;while(x%i==0)x/=i,res.pb(i);
	}
	if(x>1)res.pb(x);
	return res;
}
int main() {
	char t[55];
	while(1){
		scanf("%s",t);
		if(t[0]=='e'){return 0;}
		
		int l=1,r=1e9+2;
		while(r-l+1>2){
			int mid=(l+r)>>1;
			int t=query(l,mid);
			if(t)r=mid;else l=mid;
		}
		vector<int> fac=getfac(r);
		rep(i,0,SZ(fac)-1){
			if(query(r,r/fac[i]))r/=fac[i];
		}
		printf("! %d\n",r);fflush(stdout);
	}
	return 0;
}