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

const int N=10000005;
int mu[N],flag[N],p[N],c[N],s[N],n,cnt,x;
ll ans,num,sum;

void init(){
	mu[1]=1;
	rep(i,2,n){
		if(!flag[i]){
			p[++cnt]=i,mu[i]=-1;
			if(i*2<=n) num++,c[i]++;
		}
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			flag[i*p[j]]=1;
			c[p[j]]++,num++;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	rep(i,2,n) s[i]=s[i-1]+c[i];
}

int main(){
	read(n),init();
	ans=3*num*(num-1)/2;
	for(int i=2;i<n/i;i++)
		if(c[i]) ans-=(ll)c[i]*(s[n/i]-s[i]);
	rep(i,1,n){
		if(c[i]) ans-=(ll)c[i]*(c[i]-1)/2;
		if(mu[i]){
			x=n/i;
			sum+=(ll)mu[i]*x*(x-1)/2;
		}
	}
	ans-=(ll)n*(n-1)/2-sum;
	cout<<ans<<endl;
	return 0;
}