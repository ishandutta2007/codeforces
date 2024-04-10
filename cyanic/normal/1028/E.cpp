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

const int N=200005;
int b[N],p,n;
ll a[N],sum;

int pre(int x){
	return x==1?n:x-1;
}

int main(){
	read(n);
	rep(i,1,n){
		read(b[i]);
		if(b[i]>b[p]) p=i;
		sum+=b[i];
	}
	if(!sum){
		puts("YES");
		rep(i,1,n) printf("1 ");
		return 0;
	}
	if((ll)b[p]*n==sum){
		puts("NO");
		return 0;
	}
	rep(k,1,n)
		if(b[k]==b[p]&&b[pre(k)]!=b[p]){
			p=k;
			break;
		}
	ll las=b[p]*2; a[p]=b[p];
	for(int k=pre(p);k!=p;k=pre(k))
		a[k]=las+b[k],las=a[k];
	puts("YES");
	rep(i,1,n) printf("%lld ",a[i]);
	return 0;
}