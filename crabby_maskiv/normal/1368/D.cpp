#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int cnt[20];
int a[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=0;j<20;j++) cnt[j]+=bool(a[i]&(1<<j));
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		int x=0;
		for(j=0;j<20;j++){
			if(cnt[j]){
				cnt[j]--;
				x+=(1<<j);
			}
		}
		ans+=1ll*x*x;
	}
	cout<<ans;
	return 0;
}