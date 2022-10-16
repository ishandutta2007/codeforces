#include<bits/stdc++.h>//(o)
using namespace std;
char a[100003];string str;
vector<string>ans;
int main(){
	int n,cnt=0;
	cin>>n;
	while(cin>>str)
		a[cnt++]=str[0];
	if(cnt==1&&n==1){
		cout<<"int";
		return 0;
	}
	stack<bool>s;
	for(int i=0;i<cnt;i++){
		if(a[i]=='p')
			s.push(0),
			ans.push_back("pair<");
		else
			if(s.empty())
			{
				cout<<"Error occurred";
				return 0;
			}
			else if(s.top()==0)
				s.push(1),
				ans.push_back("int,");
			else
			{
				s.pop();
				s.pop();
				ans.push_back("int>");
				while(s.size()/2&&s.top()==1)
					s.pop(),
					s.pop(),
					ans.push_back(">");
				if(s.size()==0&&i<cnt-1)
				{
					cout<<"Error occurred";
					return 0;
				}
				if(i<cnt-1)
					s.push(1),
					ans.push_back(",");
			}
	}
	if(s.size())
		cout<<"Error occurred";
	else
		for(int i=0;i<ans.size();i++)
			cout<<ans[i];
}