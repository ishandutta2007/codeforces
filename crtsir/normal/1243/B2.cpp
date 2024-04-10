#include<bits/stdc++.h>
using namespace std;
int TT,n;
vector<int>a[26],b[26];
string s,t;
int main(){
	cin>>TT;
	while(TT--){
		cin>>n>>s>>t;
		for(int i=0;i<26;i++)a[i].clear(),b[i].clear();
		for(int i=0;i<s.size();i++)
			if(s[i]!=t[i]){
				a[s[i]-'a'].push_back(i);
				b[t[i]-'a'].push_back(i);
			}
		bool can=1;
		for(int i=0;i<26;i++)
			if((a[i].size()-b[i].size())%2){
				cout<<"No\n";
				can=0;
				break;
			}
		if(!can)continue;
		vector<pair<int,int> >ans;
		for(int i=0;i<s.size();i++)
			if(s[i]!=t[i]){
				int j; 
				for(j=i+1;j<s.size();j++)
					if(s[i]==s[j])
					{
						ans.push_back(make_pair(j,i)),
						swap(s[j],t[i]);
						break;
					}
				if(j!=s.size())continue;
				for(j=i+1;j<t.size();j++)
					if(s[i]==t[j]){
						ans.push_back(make_pair(j,j));
						ans.push_back(make_pair(j,i));
						swap(s[j],t[j]);
						swap(s[j],t[i]);
						break;
					}
			} 
		cout<<"Yes"<<endl<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
	}
}