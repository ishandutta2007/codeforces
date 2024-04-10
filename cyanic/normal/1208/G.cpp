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

const int N=1000005;
ll f[N],n,K,ans1=1,ans2=2;

int main(){
	read(n);
	read(K);
	/*
	rep(i,3,n){
		f[i]+=i;
		for(int j=i+i;j<=n;j+=i)
			f[j]-=f[i];
		f[i]--;
		//cerr<<i<<" "<<f[i]<<endl;
	}
	sort(f+3,f+n+1);
	rep(i,3,2+K)
		ans1+=f[i];
	*/
	memset(f,0,sizeof f);
	rep(i,1,n){
		f[i]+=i;
		for(int j=i+i;j<=n;j+=i)
			f[j]-=f[i];
		//cerr<<i<<" "<<f[i]<<endl;
	}
	sort(f+3,f+n+1);
	rep(i,3,2+K)
		ans2+=f[i];
	//cout<<ans1<<" "<<ans2<<endl;
	if(K==1)puts("3");
	else printf("%lld\n",ans2);
	return 0;
}