#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
int n,mask,a;
bool check(string s,int a,int b){
	s=s.substr(a,b-a);
	if(s[0]=='0'&&s.size()>1)return 0;
	else
		if(s[0]=='0')
			return 1;
	int x=0;
	while(s.size())
		x=x*10+s[0]-'0',
		s=s.substr(1);
	return (x>=0&&x<256);
}
void func(string s){
	for(int i=1;i<=3;i++)
		for(int j=i+1;j<=i+3;j++)
			for(int k=j+1;k<=j+3;k++)
				if(s.size()-k>0&&s.size()-k<4)
					if(check(s,0,i)&&check(s,i,j)&&check(s,j,k)&&check(s,k,s.size()))
						ans.push_back(s.substr(0,i)+'.'+s.substr(i,j-i)+'.'+s.substr(j,k-j)+'.'+s.substr(k,s.size()-k));
}
void swaper(string x){
	string res=x;
	reverse(x.begin(),x.end());
	func(res+x.substr(1));
	func(res+x);
}
void dfs(int used,string s)
{
	//cout<<s;
	if(s.size()==7)return;
	if(used==mask)
	{
		swaper(s);
	}
	for(int i=0;i<10;i++)
		if(mask&(1<<i))
			dfs(used|(1<<i),s+char(i+'0'));
}
int main(){
	cin>>n;
	if(n>6){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
		cin>>a,
		mask|=(1<<a);
	dfs(0,"");
		cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
}