#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
int K=2050;
int main(){
	int T; scanf("%d",&T);
	while (T--){
		ll n; scanf("%lld",&n);
		if (n%K) puts("-1");
		else{
			n/=K;
			int c=0;
			while (n) c+=n%10,n/=10;
			printf("%d\n",c);
		}
	}
	return 0;
}