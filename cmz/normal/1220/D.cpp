#include <cstdio>
#include <vector>
#include <algorithm>
 
int cnt[1001];
long long x;
int n;
std::vector<long long>vec[1001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t=0;
		scanf("%I64d",&x);
		long long tem=x;
		while((x%2ll)==0ll)++t,x>>=1ll;
		++cnt[t];
		vec[t].push_back(tem);
	}
	int ans=0,p=0;
	for(int i=0;i<=1000;i++)if(cnt[i]>ans)ans=cnt[i],p=i;
	printf("%d\n",n-ans);
	for(int i=0;i<=1000;i++)
		if(i!=p)
			for(int j=0;j<vec[i].size();j++)
				printf("%I64d ",vec[i][j]);
}