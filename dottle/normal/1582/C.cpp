#include<bits/stdc++.h>
const int N=1005005;
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int ans=1e9;
	for(int i=0;i<26;i++){
		string nw;
		vector<int> sg(n+1);
		int na=0;
		for(int j=0;j<n;j++)
			if(s[j]!=i+'a')
				nw.push_back(s[j]),na++;
			else 
				sg[nw.size()]++;
		int fl=1;
		for(int i=0;i<nw.size();i++)
			if(nw[i]!=nw[nw.size()-i-1])
				fl=0;
		if(!fl)continue;
		for(int i=0;i<=nw.size();i++){
			na+=min(sg[i],sg[nw.size()-i]);
		}
		ans=min(ans,n-na);
	}
	if(ans==1e9)
		cout<<-1<<endl;
	else cout<<ans<<endl; 
}

int main(){
	int t;cin>>t;
	while(t--)solve();
}