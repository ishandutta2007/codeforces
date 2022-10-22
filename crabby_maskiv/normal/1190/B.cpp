#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	a[0]=-1;
	int cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]==a[i-1]+1&&a[i]==a[i+1]){
			cout<<"cslnb";
			return 0;
		}
		if(a[i]==a[i-1]) cnt++;
	}
	if(cnt>1){
		cout<<"cslnb";
		return 0;
	}
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			ans+=(a[i]-a[i-1]-1);
			a[i]=a[i-1]+1;
		}
		ans%=2;
	}
	//for(i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	cout<<((ans&1)?"sjfnb":"cslnb");
	return 0;
}