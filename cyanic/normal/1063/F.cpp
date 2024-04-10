#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=(0);i<(n);++i)
using namespace std;
typedef unsigned long long ll;
 
const int N=1000005;
const int base=69;
unordered_set<ll> S;
ll p[N],h[N];char s[N];
int f[N],n,ans,pos;
 
inline ll HASH(int l,int r){
	return h[r]-p[r-l+1]*h[l-1];
}
 
inline bool judge(int x,int p){
	return S.find(HASH(p-x+1,p-1))!=S.end()
		|| S.find(HASH(p-x+2,p))!=S.end();
}
 
int main(){
	scanf("%d%s",&n,s+1);
	p[0]=1;
	rep(i,1,n){
		p[i]=p[i-1]*base;
		h[i]=h[i-1]*base+s[n+1-i];
	}
	S.insert(0);
	rep(i,1,n){
		f[i]=f[i-1]+1;
		while(!judge(f[i],i)){
			f[i]--;
			pos=i-f[i];
			int k=f[pos];
			while(S.insert(HASH(pos-k+1,pos)).second)k--;
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}