#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a,b,c,d,sz,p[N];
int x[N],y[N];
pair<int,int> l[N];

struct BIT{
    int a[N];
	BIT(){memset(a,-2,sizeof(a));}; 
    void add(int k,int p){while(k<=n)a[k]=max(a[k],p),k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans=max(ans,a[k]),k-=k&-k;return ans;}
}T;

void solve(){
	scanf("%lld%lld/%lld%lld/%lld",&n,&a,&b,&c,&d);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		l[i].second=b*y[i]-a*x[i];
		l[i].first=-d*y[i]+c*x[i];
		p[i]=l[i].second;
	}++n;
	l[n].first=0,l[n].second=0;
	sort(l+1,l+1+n);

	sort(p+1,p+1+n);
	sz=unique(p+1,p+1+n)-p-1;
	for(int i=1;i<=n;i++)
		l[i].second=-(lower_bound(p+1,p+1+sz,l[i].second)-p);
	sort(l+1,l+1+n);
//	cout<<endl;cout<<endl;for(int i=1;i<=n;i++)
//		cout<<l[i].first<<' '<<l[i].second<<endl;
	for(int i=1;i<=n;i++){
		if(l[i].first<0)continue;
		if(p[-l[i].second]<0)continue;
		int k=T.sum(-l[i].second-1);
		T.add(-l[i].second,k+1);
	}
	cout<<T.sum(n)-1<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}