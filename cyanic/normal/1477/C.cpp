#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=5005;
int x[N],y[N],vis[N],n,p,k;

ll sqr(ll x){ return x*x; }
ll dis(int a,int b){
	return sqr(x[a]-x[b])+sqr(y[a]-y[b]);
}

int main(){
	read(n);
	rep(i,1,n){
		read(x[i]),read(y[i]);
	}
	vis[p=1]=1;
	rep(i,1,n-1){
		printf("%d\n",p);
		ll mx=0;
		rep(j,1,n){
			if(!vis[j]&&dis(p,j)>=mx){
				k=j,mx=dis(p,j);
			}
		}
		vis[p=k]=1;
	}
	printf("%d\n",p);
	return 0;
}