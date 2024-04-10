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

const int N=5005,M=10000;
int a[N],n,m,now,r;

int main(){
	read(n),read(m);
	rep(i,1,n){
		int nxt=now+(i-1)/2;
		a[i]=i*M;
		if(nxt>=m){
			r=i;
			a[i]+=(nxt-m)*2*M;
			break;
		}
		now=nxt;
	}
	if(!r){
		puts("-1");
		return 0;
	}
	rep(i,r+1,n) a[i]=a[i-1]+1;
	rep(i,1,n) printf("%d ",a[i]);
	puts("");
	return 0;
}