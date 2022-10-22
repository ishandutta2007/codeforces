#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
struct seg{
	int l,r,id;
	bool operator <(const seg &x)const
	{
		return (r==x.r)?(l<x.l):(r<x.r);
	}
};
seg a[N];
int suf[N];
int ans[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			suf[i]=inf;
			a[i].id=i;
			cin>>a[i].l>>a[i].r;
		}
		suf[n+1]=inf;
		sort(a+1,a+n+1);
		for(i=n;i;i--) suf[i]=min(suf[i+1],a[i].l);
		for(i=1;i<n;i++){
			if(a[i].r<suf[i+1])	
				break;
		}
		if(i==n){
			cout<<-1<<endl;
			continue;
		}
		for(j=1;j<=i;j++) ans[a[j].id]=1;
		for(j=i+1;j<=n;j++) ans[a[j].id]=2;
		for(i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;  
	}
	return 0;
}