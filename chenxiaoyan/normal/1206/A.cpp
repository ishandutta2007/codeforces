/*








*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int mx1,mx2;
int main(){
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		mx1=max(mx1,x);
	}
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		mx2=max(mx2,x);
	}
	cout<<mx1<<" "<<mx2;
	return 0;
}