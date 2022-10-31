#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;
int n,k;
int a[N],cnt[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],cnt[i]=0;
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int ans=n,L=0;
	for(int l=1,r=0,nw=0;l<=n;l++){
		while(r<=n&&nw-(n-nw)<k){
			nw+=cnt[++r];
		}
		if(r>n)break;
		if(r-l<ans)ans=r-l,L=l;
		nw-=cnt[l];
	}
	cout<<L<<' '<<L+ans<<endl;
	int l=1,cnt=0;
	for(int i=1,s=0;i<=n;i++){
		if(a[i]<=L+ans&&a[i]>=L)s++;
		else s--;
		if(s>0){
			s=0;
			++cnt;
			if(cnt==k)break;
			cout<<l<<' '<<i<<'\n',l=i+1;
		}
	}
	cout<<l<<' '<<n<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}