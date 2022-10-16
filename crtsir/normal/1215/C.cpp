#include<bits/stdc++.h>
using namespace std;
int n,cnt,numas,numat,numbs,numbt;
string s,t;
vector<int>v,v3;
vector<int>v2; 
int main(){
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)cnt+=(s[i]-'a'+t[i]-'a');
	if(cnt%2){
		cout<<-1;
		return 0;
	}
	cnt=0;
	for(int i=0;i<n;i++)cnt+=max((s[i]-t[i]),0);
	if(cnt%2)
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
			{
				v.push_back(i);
				swap(s[i],t[i]);
				break;
			}
	for(int i=0;i<n;i++)
		if(s[i]-t[i]==1)
			v2.push_back(i);
		else
			if(s[i]-t[i]==-1)
				v3.push_back(i);
	cout<<v.size()+v2.size()/2+v3.size()/2<<endl;
	for(int i=0;i<v.size();i++)cout<<v[i]+1<<' '<<v[i]+1<<endl;
	for(int i=0;i<v2.size();i+=2)cout<<v2[i]+1<<' '<<v2[i+1]+1<<endl;
	for(int i=0;i<v3.size();i+=2)cout<<v3[i]+1<<' '<<v3[i+1]+1<<endl;
}