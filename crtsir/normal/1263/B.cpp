#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		string a;
		vector<string>v;
		cin>>n;
		map<string,bool>find;
		for(int i=0;i<n;i++)cin>>a,v.push_back(a),find[a]=1;
		map<string,int>mp;
		mp[v[0]]=1;
		vector<string>ans;
		for(int i=1;i<n;i++)
			if(mp[v[i]]){
				for(char j='0';j<='9';j++)
					if(mp[j+v[i].substr(1)]==0&&!find[j+v[i].substr(1)]){
						mp[j+v[i].substr(1)]=1;
						ans.push_back(j+v[i].substr(1));
						break;
					}
				cnt++;
			} else
				ans.push_back(v[i]),
				mp[v[i]]=1; 
		cout<<cnt<<endl<<v[0]<<endl;
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
	}
}