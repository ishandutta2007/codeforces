#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){
	lli n,k,q;
	lli t[200002],ans[200002];
	ans[0]=0;
	for(int i=0;i<=200001;i++){
		t[i]=0;
	}
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		t[a]++;
		cin>>a;
		t[a+1]--;
	}
	for(int i=1;i<=200001;i++){
		t[i]+=t[i-1];
	}
	for(int i=1;i<=200001;i++){
		if(t[i]>=k){
			ans[i]=1;
		}
		else{
			ans[i]=0;
		}
		ans[i]+=ans[i-1];
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<ans[b]-ans[a-1]<<'\n';
	}
}