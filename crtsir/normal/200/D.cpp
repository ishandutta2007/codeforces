#include<bits/stdc++.h>
using namespace std;
map<string,vector<vector<int> > >mp;
map<string,int>mp2;
int check(string s,vector<string>s2){
	//for(int i=0;i<s2.size();i++)cout<<mp2[s2[i]]<<' ';
	//cout<<endl;
	int ans=mp[s].size();
	//cout<<s<<'K';
	for(int i=0;i<mp[s].size();i++)
	{
		if(mp[s][i].size()!=s2.size())
		{
		//	cout<<i<<' ';
			ans--;
			continue;
		}
		for(int j=0;j<mp[s][i].size();j++)
			if(mp[s][i][j]&&mp[s][i][j]!=mp2[s2[j]])
			{
				ans--;
	//			cout<<i<<' ';
				break;
			}
	}
	//cout<<endl;
	return ans;	
}
int main(){
	string s;
	int na,nb,nc;
	cin>>na;
	getline(cin,s);
	for(int i=0;i<na;i++)
	{
		getline(cin,s);
		string x1="";
		int j=0;
		while(s[j]==' ')j++;
		while(s[j]!=' ')j++;
		while(s[j]==' ')j++;
		while(s[j]!=' '&&s[j]!='(')x1+=s[j],j++;
		while(s[j]!='(')j++;
	//	if(x1!="f")cout<<x1<<endl;
		j++;
		vector<int>v;
		while(s[j]!=')'){
			if(s[j]=='i')v.push_back(1),j+=2;
			if(s[j]=='d')v.push_back(2),j+=5;
			if(s[j]=='s')v.push_back(3),j+=5;
			if(s[j]=='T')v.push_back(0);
			j++;
		}
		mp[x1].push_back(v);
	}
	cin>>nb;
	for(int i=0;i<nb;i++){
		cin>>s;
		string s2;
		cin>>s2;
		if(s=="int")mp2[s2]=1;
		if(s=="double")mp2[s2]=2;
		if(s=="string")mp2[s2]=3;
	}
	cin>>nc;
	getline(cin,s);
	for(int i=0;i<nc;i++){
		getline(cin,s);
		int j=0;
		string s2="",s3="";
		while(s[j]==' ')j++;
		while(s[j]!='('&&s[j]!=' '){
			s2+=s[j];
			j++;
		}
		while(s[j]!='(')j++;
		vector<string>v;
		j++;
		for(j;j<s.size();j++)
		{
			if(s[j]==','||s[j]==')')
			{
				v.push_back(s3);
				s3="";
				continue;
			}
			if(s[j]!=' ')
				s3+=s[j];
		}
		cout<<check(s2,v)<<endl;
	}
}