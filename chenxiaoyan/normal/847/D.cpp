/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int lowbit(int x){return x&-x;}
const int N=200000;
int n,m;
int a[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)a[i]=lower_bound(nums.begin(),nums.end(),max(0,a[i]-i))-nums.begin()+1;
}
struct bitree{
	int sum[N+1];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x){
		while(x<=n)sum[x]++,x+=lowbit(x);
	}
	int Sum(int x){
		if(x<0)return 0;
		int ans=0;
		while(x)ans+=sum[x],x-=lowbit(x);
		return ans;
	}
}bit;
int main(){
	cin>>n>>m;
	m--;
	for(int i=1;i<=n;i++)cin>>a[i],nums.pb(max(0,a[i]-i));
	discrete();
	bit.init();
	int ans=0;
	for(int i=1;i<=n;i++){
		bit.add(a[i]);
		ans=max(ans,bit.Sum(upper_bound(nums.begin(),nums.end(),m-i)-nums.begin()));
//		cout<<bit.Sum(upper_bound(nums.begin(),nums.end(),m-i)-nums.begin())<<"\n";
	}
	cout<<ans;
	return 0;
}
/*1
4 4
2 1 2 3
*/