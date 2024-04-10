#include<bits/stdc++.h>
#define int long long
const int N=1005000,mod=998244353;
using namespace std;

int s,n;
int a[N],b[N],ia[N],ib[N];
int sm[N];

void solve(){
	cin>>n>>s;
	for(int i=1;i<=n;i++)a[i]=b[i]=ia[i]=ib[i]=0;
	for(int i=1;i<=n;i++)cin>>ia[i],a[ia[i]]=i;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>0)ib[b[i]]=i;
	}
	for(int i=1;i<=n;i++)b[i]=ib[i]?ib[i]:-1;
	for(int i=1;i<=n;i++)ib[i]=0;
	for(int i=1;i<=n;i++)if(b[i]>0)ib[b[i]]=1;
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1];
		if(ib[a[i]]==0)sm[i]++;
	}
	int res=1,S=0;
	for(int i=1;i<=n;i++){
		if(b[i]==-1)
			res=res*(sm[min(i+s,n)]-S)%mod,S++;
		else 
			if(ia[b[i]]>i+s)res=0;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}