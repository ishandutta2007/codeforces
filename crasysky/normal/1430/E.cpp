#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5; 
int n,C[N];
void add(int x){ for (;x;x-=x&-x) ++C[x]; }
int sum(int x){
	int s=0; for (;x<=n;x+=x&-x) s+=C[x]; return s; 
}
char s[N]; int a[N],b[N],ca[30],cb[30],p[30][N];
int main(){
	scanf("%d%s",&n,s);
	rep(i,1,n) b[i]=a[i]=s[i-1]-'a'+1;
	reverse(b+1,b+1+n);
	rep(i,1,n) p[a[i]][++ca[a[i]]]=i;
	rep(i,1,n) b[i]=p[b[i]][++cb[b[i]]];
	ll s=0; rep(i,1,n) s+=sum(b[i]),add(b[i]);
	cout<<s<<endl;
	return 0;
}