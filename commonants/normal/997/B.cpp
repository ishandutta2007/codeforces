#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MX=1000005,md=998244353;
// f[i]:rev answer of i.
// f[i]=3^i*i-\sum_{j=1}^i f[j-1]*3*3^{(i-j)*(i-j)}
int n;
int vis[MX];
int bf(){
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=j;k<=n;k++){
				vis[i*1+(j-i)*5+(k-j)*10+(n-k)*50]=1;
			}
	int ans=0;
	for(int i=0;i<MX;i++)ans+=vis[i];
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	if(n<=500)cout<<bf()<<endl;
	else cout<<(ll)n*49-247<<endl;
	// 12+236=248
	return 0;
}
// r-l=max-min

// f[i][j]: i  j 
// f[i][j](...)