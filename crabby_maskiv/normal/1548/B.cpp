#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll st[20][N];
int lg[N];
ll a[N];
ll qry(int l,int r){
	int c=lg[r-l+1];
	return __gcd(st[c][l],st[c][r-(1<<c)+1]);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	for(i=2;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=n;i;i--){
			a[i]-=a[i-1];
			if(a[i]<0) a[i]=-a[i];
		}
		for(i=1;i<=n;i++) st[0][i]=a[i];
		for(j=1;j<20;j++)
			for(i=1;i+(1<<j)-1<=n;i++)
				st[j][i]=__gcd(st[j-1][i],st[j-1][i+(1<<j-1)]);
		int ans=1;
		for(i=2;i<=n;i++){
			int l=1,r=i-1;
			while(l<r){
				int mid=l+r>>1;
				if(qry(mid+1,i)>1) r=mid;
				else l=mid+1;
			}
			if(qry(l+1,i)>1) ans=max(ans,i-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}