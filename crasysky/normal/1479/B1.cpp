#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; int a[N],b[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int ans=0,c=1; b[1]=2;
	rep(i,2,n)
		if (a[i]==a[i-1]) ++c,b[i]=b[i-1];
		else{
			ans+=min(b[i-1],c),c=1;
			if (a[i]!=a[i-2]) b[i]=2;
			else if (a[i-2]==a[i-3]) b[i]=1;
			else b[i]=b[i-2];
		}
	printf("%d\n",ans+min(b[n],c));
}