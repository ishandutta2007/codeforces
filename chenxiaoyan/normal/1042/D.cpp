/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int lowbit(int x){return x&-x;}
const int N=200000;
int n,m; 
int Sum[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
}
struct bitree{
	int sum[N+1];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int v){
		int x=v;
		while(x<=n)sum[x]++,x+=lowbit(x);
	}
	void del(int v){
		int x=v;
		while(x<=n)sum[x]--,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",Sum+i),Sum[i]+=Sum[i-1],nums.pb(Sum[i]);
	discrete();
	int ans=0; 
	for(int i=1;i<=n;i++)bit.add(lower_bound(nums.begin(),nums.end(),Sum[i])-nums.begin()+1);
	for(int i=0;i<n;i++)i&&(bit.del(lower_bound(nums.begin(),nums.end(),Sum[i])-nums.begin()+1),0),ans+=bit.Sum(lower_bound(nums.begin(),nums.end(),Sum[i]+m)-nums.begin());
	cout<<ans;
	return 0;
}