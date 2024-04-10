#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[155555];
int main(){
	int t; cin>>t; while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int lo=0,le=0;
		for(int i=1;i<=n;++i)if(a[i]&1){if(a[i]>=lo)lo=a[i];else goto f;}
			else {if(a[i]>=le)le=a[i];else goto f;}
		puts("Yes"); continue;
		f:puts("No");
	}
	
}