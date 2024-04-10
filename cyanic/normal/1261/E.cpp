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

const int N=1005;
int ans[N][N],a[N],p[N],n,mx;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		mx=max(mx,a[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y){
		return a[x]>a[y];
	});
	rep(i,1,n){
		int t=p[i],s=i;
		s=s%(mx+1);
		if(!s)s=mx+1;
		rep(j,1,a[t]){
			ans[s][t]=1;
			++s;
			if(s>mx+1)s=1;
		}
	}
	printf("%d\n",mx+1);
	rep(i,1,mx+1){
		rep(j,1,n)printf("%d",ans[i][j]);
		puts("");
	}
	
	return 0;
}