#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int a[maxn];
int n,k;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ci=1;
	while(k){
		if(ci>n){
			while(k--) cout<<0<<endl;
			return 0;
		}
		if(ci==1){
			k--;
			cout<<a[ci]<<endl;
			ci++;
		}else if(a[ci]==a[ci-1]){
			ci++;
		}else{
			k--;
			cout<<a[ci]-a[ci-1]<<endl;
			ci++;
		}
	}
	return 0;
}