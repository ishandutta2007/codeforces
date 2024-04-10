/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int lowbit(int x){return x&-x;}
const int N=100000;
int n;
int x0[N+1],y[N+1];
vector<int> nums;
map<int,int> v;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)x0[i]=lower_bound(nums.begin(),nums.end(),x0[i])-nums.begin()+1,y[i]=lower_bound(nums.begin(),nums.end(),y[i])-nums.begin()+1;
}
int a[4*N+2];
struct bitree{
	int sum[4*N+2];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x){
		int val=v[nums[x-1]];
		while(x<=nums.size())sum[x]+=val,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x0[i]>>y[i],nums.pb(x0[i]),nums.pb(y[i]);
	nums.pb(0);
	sort(nums.begin(),nums.end());
	int tmp=nums.size();
	for(int i=1;i<tmp;i++){
		v[nums[i]]=1;
		if(nums[i]-1>nums[i-1])nums.pb(nums[i]-1),v[nums[i]-1]=nums[i]-1-nums[i-1];
	}
	discrete();
	for(int i=1;i<=nums.size();i++)a[i]=i;
	for(int i=1;i<=n;i++)swap(a[x0[i]],a[y[i]]);
//	for(int i=1;i<=nums.size();i++)cout<<a[i]<<" "<<nums[a[i]-1]<<" "<<v[nums[a[i]-1]]<<"\n";
	int ans=0;
	bit.init();
	for(int i=nums.size();i;i--){
		ans+=v[nums[a[i]-1]]*bit.Sum(a[i]-1);
		bit.add(a[i]);
	}
	cout<<ans;
	return 0;
}
/*1
2
4 2
1 4
*/
/*2
1
1000000000 1
*/