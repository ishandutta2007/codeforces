#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;

int n,q,x,k;
int s[2*N][N],cnt[N];
void solve(int *a,int *b){
	for(int i=1;i<=n;++i)++cnt[a[i]];
	for(int i=1;i<=n;++i)b[i]=cnt[a[i]];
	for(int i=1;i<=n;++i)--cnt[a[i]];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[0][i];
	for(int i=1;i<=n<<1;i++)
		solve(s[i-1],s[i]);
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>x>>k;
		if(k>2*n)
			k=2*n;
		cout<<s[k][x]<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--)solve();
}