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
ll a[N],b[N],n,aim;

void rmain(){
	read(n);
	rep(i,1,n) read(a[i]);
	for(aim=0;;aim++){
		ll flag=0,s=0;
		REP(i,aim) s|=1ll<<i;
		b[n]=a[n]+s;
		per(i,n-1,1){
			b[i]=min(b[i+1],a[i]+s);
			if(b[i]<a[i]) flag=1;
		}
		if(!flag) break;
	}
	printf("%lld\n",aim);
}

int main(){
	int T; read(T);
	while(T--) rmain();

	return 0;
}