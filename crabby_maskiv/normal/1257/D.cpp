#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
ll a[N];
ll p[N],s[N];
ll mx[N];
int nxt[N],dp[N];
ll st[N][20];
int lg[N];
ll qry(int l,int r){
	int len=r-l+1;
	return max(st[l][lg[len]],st[r-(1<<lg[len])+1][lg[len]]);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	lg[1]=0;
	for(i=2;i<N;i++) lg[i]=lg[i-1]+(i==(1<<lg[i-1]+1));
	while(T--){
		cin>>n;
		for(i=1;i<=n+1;i++) mx[i]=nxt[i]=0;
		for(i=1;i<=n;i++){
			cin>>a[i];st[i][0]=a[i];
		}
		for(j=1;j<20;j++)
			for(i=1;i+(1<<j)-1<=n;i++)
				st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
		cin>>m;
		for(i=1;i<=m;i++){
			cin>>p[i]>>s[i];
			mx[s[i]]=max(mx[s[i]],p[i]);
		}
		for(i=n;i;i--) mx[i]=max(mx[i],mx[i+1]);
		for(i=1;i<=n;i++) if(a[i]>mx[1]) break;
		if(i<=n){
			cout<<-1<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			if(qry(i,n)<=mx[n-i+1]){
				nxt[i]=n+1;
				continue;
			}
			int l=i,r=n;
			while(r>l){
				int mid=(l+r)>>1;
				if(qry(i,mid)>mx[mid-i+1]) r=mid;
				else l=mid+1;
			}
			nxt[i]=l;
		}
		for(i=1;i<=n+1;i++) dp[i]=n+1;
		dp[1]=0;
		for(i=1;i<=n;i++)
			dp[nxt[i]]=min(dp[nxt[i]],dp[i]+1);
		cout<<dp[n+1]<<endl;
	}
	return 0;
}