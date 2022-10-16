#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,a[200005],c[200005],book[200005],cnt[200005];
vector <int>d[200005];
inline bool check(int num){
	for (int i=1;i<=n;i++)
		book[i]=i%num+1;
	int fg=1;
	for(int i=n;i>=1;i--){
		cnt[book[i]]++;
		if (cnt[book[i]]>c[a[i]])fg=0;
	}
	for (int i=1;i<=n;i++)cnt[book[i]]--;
	return fg;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=k;i++)scanf("%d",&c[i]);
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1; 
	} 
	cout<<ans<<endl;
	check(ans);
	for (int i=1;i<=n;i++)
		d[book[i]].push_back(i);
	for (int i=1;i<=ans;i++){
		printf("%d ",d[i].size());
		for (int j=0,len=d[i].size();j<len;j++)
			printf("%d ",a[d[i][j]]);
		cout<<endl;
	}
	return 0;
}