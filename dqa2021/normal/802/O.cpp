#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
#include<iostream>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const ll INF=1e18;

int n,k;
int a[500010],b[500010];
int check(ll v,bool f=0){
	ll res=0; int tot=0;
	priority_queue<int> A;
	priority_queue<int,vector<int>,greater<int> > B;
	for (int i=n;i;i--){
		B.push(b[i]);
		ll X=a[i]+v+B.top(),Y=A.empty()?INF:a[i]-A.top();
		if (min(X,Y)>0) continue;
		if (Y<X){
			res+=Y; A.pop(); A.push(a[i]);
		}
		else{
			res+=X; tot++; B.pop(); A.push(a[i]);
		}
	}
	if (f) cout<<res-k*v<<endl;
	return tot;
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	//printf("test %d\n",check(-137));
	//return 0;
	//for (int i=1;i<=200;i++) printf("f %d = %d\n",i,check(-i));
	ll l=1,r=2e9,mid;
	while (l<r){
		//find rightest such that smallest k <= k0
		mid=l+r+1>>1;
		if (check(-mid)<=k) l=mid;
		else r=mid-1;
	}
	//printf("check %lld %d\n",l,check(-l));
	check(-l,1);
	return 0;
}