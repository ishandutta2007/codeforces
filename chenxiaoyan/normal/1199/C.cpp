#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=400000;
int n,m;
int a[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=n;i++)a[i]=lower_bound(nums.begin(),nums.end(),a[i])-nums.begin();
}
int cnt[N+1],Sum[N+1];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i),nums.pb(a[i]);
	discrete();
	int most=-1;
	for(int i=1;i<=nums.size();i++)if((long long)ceil(log2(i))*n>8ll*m){most=i-1;break;}
	if(!~most)return puts("0"),0;
	for(int i=1;i<=n;i++)cnt[a[i]+1]++;
	for(int i=1;i<=nums.size();i++)Sum[i]=Sum[i-1]+cnt[i];
	int ans=inf;
	for(int i=1;i+most-1<=nums.size();i++)ans=min(ans,Sum[i-1]+Sum[nums.size()]-Sum[i+most-1]);
	printf("%d",ans);
	return 0;
}