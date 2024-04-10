#include<bits/stdc++.h>
using namespace std;
int main(){
	int Q;cin>>Q;while(Q--){
		int n,k;cin>>n>>k;
		string a;cin>>a;
		int fp=0,lp=n-1;
		while(a[fp]=='.')fp++;
		while(a[lp]=='.')lp--;
		int cnt=0;int ans=1;
		for(int i=fp;i<lp;i+=k){
			while(a[i]=='.')i--;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}