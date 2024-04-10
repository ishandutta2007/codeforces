#include<bits/stdc++.h>
using namespace std;
int n,a[1003],T;
bool ok[1003];
int mex(){
	memset(ok,0,sizeof(ok));
	for(int i=0;i<n;i++)ok[a[i]]=1;
	for(int i=0;i<n;i++)if(!ok[i])return i;
	return n;
}
bool go(){
	for(int i=0;i<n-1;i++)if(a[i]>a[i+1])return 0;
	return 1;
}
bool yes[1003];
void solve(){
	memset(yes,0,sizeof(yes));
	vector<int>res;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(mex()==n){
		res.push_back(0),a[0]=mex(); 
	}
	for(int i=1;i<=2*n+1;i++){
		if(go())break;
		int val=mex(); 
		if(mex()==n){
			for(int i=0;i<n;i++)if(!yes[i]){
				res.push_back(i),a[i]=n;
				break;
			}
			continue;
		}
		res.push_back(val);
		a[val]=val;yes[val]=1;
//		cout<<i<<' '<<val<<"\n";
	}
	cout<<res.size()<<"\n";
	for(int i=0;i<res.size();i++)cout<<res[i]+1<<" ";
	puts("");
}
int main(){
	cin>>T;
	while(T--)solve();
}