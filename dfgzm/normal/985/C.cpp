#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn],cnt;
ll S[maxn],ans;
int main(){
	cin>>n>>m>>k;
	for(i=1;i<=n*m;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n*m);
	int num=0;
	for(i=n*m;i>=1;i--){
		if(a[i]-a[1]<=k && num>=m-1){
			num-=m-1;
			ans+=a[i];
			cnt++;
		}else ++num;
	}
	if(cnt==n)cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}