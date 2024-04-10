#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];
int b[maxn];
int c[maxn];
int x;

int main(){
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]==(a[i]&x)) continue;
		c[a[i]&x]++;
	}
	int ans=1234567;
	for(int i=0;i<maxn;i++){
		if(b[i]>=2)ans=min(ans,0);
		if(b[i]>=1&&c[i]>=1) ans=min(ans,1);
		if(c[i]>=2) ans=min(ans,2);
		//cout<<b[i]<<c[i]<<i<<':'<<ans<<endl;
	}
	if(ans==1234567) cout<<-1;
	else cout<<ans;
	return 0;
}