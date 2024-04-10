#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int x[maxn];
int minn=0x7FFFFFFF;
int ans;

int main(){
	cin>>n;
	ans=n;
	for(int i=0;i<n;i++){
		cin>>x[i];
		minn=min(minn,x[i]);
	}
	int lp=0-n-n;
	for(int i=0;i<n;i++){
		if(x[i]==minn){
			ans=min(ans,i-lp);
			lp=i;
		}
	}
	cout<<ans;
	return 0;
}