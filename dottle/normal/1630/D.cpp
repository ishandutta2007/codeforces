#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int a[N],b[N];
int J[N],O[N];

void solve(){
	int n,m;cin>>n>>m;
	int gc=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans+=max(0ll,a[i]);
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		gc=__gcd(gc,x);
	}
	int sj=0,so=0;
	for(int i=1;i<=gc;i++){
		vector<int> nw;
		for(int j=i;j<=n;j+=gc)
			nw.push_back(a[j]);
		sort(nw.begin(),nw.end());
		int pos=0,sum=0;
		for(int j=0;j<nw.size()&&nw[j]<=0;j++)
			pos=j+1,sum-=nw[j];
		if(pos&1){
			J[i]=sum;
			O[i]=-1e18;
			if(pos!=0)O[i]=max(O[i],J[i]+2*nw[pos-1]);
			if(pos!=nw.size())O[i]=max(O[i],J[i]-2*nw[pos]);
		}else{
			O[i]=sum;
			J[i]=-1e18;
			if(pos!=0)J[i]=max(J[i],O[i]+2*nw[pos-1]);
			if(pos!=nw.size())J[i]=max(J[i],O[i]-2*nw[pos]);
		} 
		sj+=J[i],so+=O[i];
	}
	cout<<ans+max(sj,so)<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}