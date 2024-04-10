#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
int p[N],l,r,mid,n;
ll c[N],s[N];

#define lowbit(x) (x&-x)
inline void add(int x,int y){
	for(;x<=n;x+=lowbit(x))
		c[x]+=y;
}
inline ll qry(int x){
	ll res=0;
	for(;x;x-=lowbit(x))
		res+=c[x];
	return res;
}

int main(){
	read(n);
	rep(i,1,n){
		read(s[i]);
		add(i,i);
	}
	per(i,n,1){
		l=1,r=n;
		for(;l<r;){
			mid=(l+r+1)>>1;
			if(qry(mid-1)<=s[i])l=mid;
			else r=mid-1;
		}
		p[i]=l;
		add(p[i],-p[i]);
	}
	rep(i,1,n)
		printf("%d ",p[i]);
	puts("");
	
	return 0;
}