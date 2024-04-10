/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=300000;
int n;
int a[N+1];
vector<int> nums;
int mn[N+1],mx[N+1];
void mian(){
	cin>>n;
	nums.clear();
	for(int i=1;i<=n;i++)cin>>a[i],nums.pb(a[i]);
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)mn[a[i]]=inf,mx[a[i]]=0;
	for(int i=1;i<=n;i++)mn[a[i]]=min(mn[a[i]],i),mx[a[i]]=max(mx[a[i]],i);
	int now=1,ans=1;
	for(int i=1;i<nums.size();i++)
		if(mx[nums[i-1]]<mn[nums[i]])now++,ans=max(ans,now);
		else now=1;
	cout<<nums.size()-ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7
*/