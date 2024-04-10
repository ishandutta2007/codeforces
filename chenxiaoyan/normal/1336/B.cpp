/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c;
long long solve(){
	long long ans=4e18;
	for(int i=0;i<a.size();i++){
		vector<int>::iterator fd1=upper_bound(b.begin(),b.end(),a[i]),fd2=lower_bound(c.begin(),c.end(),a[i]);
		if(fd1==b.begin())continue;
		if(fd2==c.end())continue;
		long long x=a[i],y=*--fd1,z=*fd2;
		ans=min(ans,(x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z));
	}
	return ans;
}
void mian(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	a.resize(n);b.resize(m);c.resize(s);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	for(int i=0;i<s;i++)scanf("%d",&c[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	long long ans=4e18;
	ans=min(ans,solve());
	swap(b,c);
	ans=min(ans,solve());
	swap(a,c);
	ans=min(ans,solve());
	swap(b,c);
	ans=min(ans,solve());
	swap(a,c);
	ans=min(ans,solve());
	swap(b,c);
	ans=min(ans,solve());
	printf("%lld\n",ans);
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}