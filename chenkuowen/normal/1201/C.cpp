#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main(){
	int n,k; scanf("%d%d",&n,&k);
	a.resize(n+1); b.resize(n+1);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int mid=n+1>>1,ans=0;
	for(int i=mid+1;i<=n;++i) b[i]=a[i]-a[i-1];
	for(int i=mid+1;i<=n;++i){
//		printf("<%d>",b[i]);
		if(k>=1ll*b[i]*(i-mid)){
			k-=b[i]*(i-mid);
			ans+=b[i];
		}else{
			ans+=k/(i-mid);
			k=0;
		}
	}
	printf("%d\n",a[mid]+ans+(k/(n-mid+1)));
	return 0;
}