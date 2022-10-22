#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;while (T--){
		cin>>n;
		int a=0,b=1e9;
		for (int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			a=max(a,x);
			b=min(b,y);
		}
			cout<<max(0,a-b)<<"\n";
	}
}