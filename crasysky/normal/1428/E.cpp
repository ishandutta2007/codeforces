#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<long long,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6,P=1e9+7; int a[N],b[N]; priority_queue< pr > q;
ll Q(int i,int k){
	int x=a[i]/k; return (ll)(a[i]%k)*(x+1)*(x+1)+(ll)(k-a[i]%k)*x*x;
}
int main(){
	int n,k; scanf("%d%d",&n,&k); k-=n; ll s=0;
	rep(i,1,n) scanf("%d",&a[i]),s+=Q(i,1),b[i]=1,q.push(mp(Q(i,1)-Q(i,2),i));
	rep(i,1,k){
		s-=q.top().fi; int x=q.top().se; q.pop();
		++b[x]; if (b[x]<a[x]) q.push(mp(Q(x,b[x])-Q(x,b[x]+1),x));
	}
	printf("%lld\n",s);
	return 0;
}