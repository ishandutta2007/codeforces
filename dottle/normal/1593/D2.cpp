#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	int ans=0,fl=0,n;
	cin>>n;
	vector<int> a(n+5),f(n+5),b(n+5);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int c0=0;
		for(int j=1;j<=n;j++)
			b[j]=abs(a[j]-a[i]),c0+=!b[j];
		if(c0>=n/2)fl=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k*k<=b[j];k++)
				if(b[j]%k==0){
					int nw=k,cnt=0;
					for(int l=1;l<=n;l++)
						cnt+=b[l]%nw==0;
					if(cnt>=n/2)
						ans=max(ans,nw);
					nw=b[j]/k,cnt=0;
					for(int l=1;l<=n;l++)
						cnt+=b[l]%nw==0;
					if(cnt>=n/2)
						ans=max(ans,nw);
				}
		}
	}
	if(fl)cout<<-1<<endl;
	else cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}