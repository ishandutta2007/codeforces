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
int n;
int a[N+1];
int b[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)
		b[i]=lower_bound(nums.begin(),nums.end(),-a[i])-nums.begin()+1,
		a[i]=lower_bound(nums.begin(),nums.end(),a[i])-nums.begin()+1;
}
struct bitree{
	int sum[2*N+1];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x){
		while(x<=nums.size())sum[x]++,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]-=x;
		nums.pb(a[i]);
		nums.pb(-a[i]);
	}
	discrete();
	int ans=0;
	bit.init();
	for(int i=n;i;i--){
		ans+=bit.Sum(a[i]-1);
		bit.add(b[i]);
	}
	cout<<ans;
	return 0;
}