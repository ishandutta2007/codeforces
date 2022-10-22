#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
int main(){
	ll sum=0;
	int n; scanf("%d",&n); a.resize(n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int cnt=0;
	for(int i=1;i<n;++i)
		if(a[i]-a[i-1]==0){
			++cnt;
			if((i>=2&&a[i-2]==a[i]-1)||cnt>1||(i==1&&a[i]==0)){
				puts("cslnb");
				return 0;
			}
		}
	for(int i=0;i<n;++i) sum+=a[i]-i;
	if((sum)%2==0) puts("cslnb");
	else puts("sjfnb");
	return 0;
}