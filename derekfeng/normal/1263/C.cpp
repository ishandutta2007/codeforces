#include <bits/stdc++.h>
using namespace std;
int t,n;
map<int,int> mp;
int main(){
	cin>>t;
	while (t--){
		mp.clear();
		cin>>n;
		mp[0]++;
		for (int i=1;i*i<=n;i++){
			mp[n/i]++;
			mp[i]++;
		}
		cout<<mp.size()<<"\n";
		for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
			cout<<(it->first)<<" ";puts("");
	}
}