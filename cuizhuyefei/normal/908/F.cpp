#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
const int N = 333333;
int n,a[N];char op[N];ll res;
int main() {
	read(n);rep(i,1,n){read(a[i]);char t[5];scanf("%s",t);op[i]=t[0];}
	bool bo=0;rep(i,1,n)bo|=op[i]=='G';
	if(!bo){
		int fi=0,se=0;
		rep(i,1,n)if(op[i]=='B'){if(!fi)fi=a[i];se=a[i];}res+=se-fi;
		fi=0;se=0;
		rep(i,1,n)if(op[i]=='R'){if(!fi)fi=a[i];se=a[i];}res+=se-fi;
		cout<<res;return 0;
	}
	int lst=0,bg,ed,fi;
	rep(i,1,n)if(op[i]=='G')ed=i;per(i,n,1)if(op[i]=='G')bg=i;
	fi=0;rep(i,1,bg)if(op[i]=='B')if(!fi)fi=i;if(fi)res+=a[bg]-a[fi];
	fi=0;rep(i,1,bg)if(op[i]=='R')if(!fi)fi=i;if(fi)res+=a[bg]-a[fi];
	fi=0;per(i,n,ed)if(op[i]=='B')if(!fi)fi=i;if(fi)res+=a[fi]-a[ed];
	fi=0;per(i,n,ed)if(op[i]=='R')if(!fi)fi=i;if(fi)res+=a[fi]-a[ed];
	lst=bg;rep(i,bg+1,n)if(op[i]=='G'){
		ll now=a[i]-a[lst];int cnt=0;
		Vi s;rep(j,lst,i)if(op[j]!='B')s.pb(a[j]);
		if(SZ(s)>2){cnt++;int mn=0;rep(k,0,SZ(s)-2)mn=max(mn,s[k+1]-s[k]);now+=a[i]-a[lst]-mn;}
		s.clear();rep(j,lst,i)if(op[j]!='R')s.pb(a[j]);
		if(SZ(s)>2){cnt++;int mn=0;rep(k,0,SZ(s)-2)mn=max(mn,s[k+1]-s[k]);now+=a[i]-a[lst]-mn;}
		if(cnt==2)now=min(now,2LL*(a[i]-a[lst]));
		res+=now;lst=i;
	}
	cout<<res;
	return 0;
}