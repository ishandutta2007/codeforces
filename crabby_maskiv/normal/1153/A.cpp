#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
ll a[N],b[N];
int main()
{
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	int ans=0x3f3f3f3f,pos=0;
	for(i=1;i<=n;i++){
		if(m<=a[i]){
			if(a[i]-m<ans){
				ans=a[i]-m;
				pos=i;
			}
		}
		else{
			ll ti=(m-a[i]+b[i]-1)/b[i];
			ti=a[i]+ti*b[i]-m;
			if(ti<ans){
				ans=ti;
				pos=i;
			}
		}
	}
	cout<<pos;
	return 0;
}