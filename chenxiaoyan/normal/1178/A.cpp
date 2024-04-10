#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100;
int n;
int a[N+1];
vector<int> ans;
int main(){
	scanf("%d",&n);
	int sumt=0,sum=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),sumt+=a[i];
	sum+=a[1];ans.pb(1);
	for(int i=2;i<=n;i++)if(a[1]>=a[i]*2)sum+=a[i],ans.pb(i);
	if(sum>sumt/2){
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	}
	else puts("0");
	return 0;
}