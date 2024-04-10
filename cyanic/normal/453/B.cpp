#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
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

const int N=105;
int b[N],res[N],n,cur,ans=1e9;
pii a[N];

void dfs(int k,int sum){
	if(sum>=ans) return;
	if(cur==0||k==1){
		int s=0;
		rep(i,1,n){
			s+=abs(a[i].fi-b[i]);
		}
		if(s>=ans) return;
		ans=s;
		rep(i,1,n){
			res[a[i].se]=b[i];
		}
		return;
	}
	int flag=0;
	rep(i,cur+1,n){
		if(__gcd(b[i],k)>1){
			flag=1;
			break;
		}
	}
	if(!flag){
		b[cur--]=k;
		dfs(k-1,sum+abs(a[cur+1].fi-k));
		b[++cur]=1;
	}
	dfs(k-1,sum);
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i].fi);
		a[i].se=i;
		b[i]=1;
	}
	sort(a+1,a+n+1);
	cur=n,dfs(58,0);
	rep(i,1,n){
		printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}