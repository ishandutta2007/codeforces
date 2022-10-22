#include<bits/stdc++.h>
using namespace std;
int T,n,d[300004];
void solve(){
	cin>>n;
	int t=0;
	for(int i=0;i<n;i++){
		int x,lst=1e9;cin>>x;
		while(t>0&&d[t-1]<x)lst=d[t-1],t--;
		d[t++]=min(lst,x);
	}
	if(t>1)puts("NO");
	else puts("YES");
}
int main(){
	cin>>T;
	while(T--)solve();
}