/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=200000;
int lowbit(int x){return x&-x;}
int n;
int a[N+1];
vector<int> pos[N+1];
struct bitree{
	int sum[N+1];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x){
		while(x<=n)sum[x]++,x+=lowbit(x);
	}
	void del(int x){
		while(x<=n)sum[x]--,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]<n&&(pos[a[i]].pb(i),0);
	for(int i=1;i<=n;i++)bit.add(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=bit.Sum(min(n,a[i]))-(i<=a[i]);
		for(int j=0;j<pos[i].size();j++)bit.del(pos[i][j]);
	}
	cout<<ans/2;
	return 0;
}