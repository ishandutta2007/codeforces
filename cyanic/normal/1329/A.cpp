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

const int N=100005;
int l[N],rk[N],ans[N],n,m,las;

int main(){
	read(n),read(m);
	rep(i,1,m) read(l[i]);
	las=n+1;
	per(i,m,1){
		ans[i]=min(n-l[i]+1,las-1);
		las=ans[i];
	}
	if(ans[1]<1) return puts("-1"),0;
	l[0]=1;
	rep(i,1,m){
		ans[i]=min(ans[i-1]+l[i-1],ans[i]);
	}
	if(ans[m]+l[m]-1<n) return puts("-1"),0;
	rep(i,1,m) printf("%d ",ans[i]);
	puts("");
	return 0;
}