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

const int N=505;
int a[N],q[N],n,K,cnt,A,B;

int main(){
	read(n),read(K);
	rep(i,1,n){
		a[i]=-1;
	}
	rep(i,1,n-K+1){
		cnt=0;
		rep(j,1,n){
			if(a[j]>=0) continue;
			if(cnt<K) q[++cnt]=j;
		}
		putchar('?');
		rep(j,1,cnt){
			printf(" %d",q[j]);
		}
		puts("");
		fflush(stdout);
		int x,y;
		read(x),read(y);
		a[x]=y;
	}
	cnt=0;
	rep(i,1,n){
		if(a[i]==-1){
			q[++cnt]=i;
		}
		else if(!A){
			A=i;
		}
		else if(!B){
			B=i;
		}
	}
	if(a[A]>a[B]) swap(A,B);
	assert(cnt==K-1);
	int ans=1;
	rep(i,1,cnt){
		putchar('?');
		rep(j,1,n){
			if(j!=q[i]&&a[j]==-1){
				printf(" %d",j);
			}
		}
		printf(" %d %d\n",A,B);
		fflush(stdout);
		int x,y;
		read(x),read(y);
		ans+=(x==B);
	}
	cout<<"! "<<ans<<endl;
	fflush(stdout);
    return 0;
}