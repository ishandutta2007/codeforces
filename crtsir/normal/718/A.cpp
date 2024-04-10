#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a,cnt=-1;
	string s;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='.'){
			for(int i=n-1;i>=0;i--)if(s[i]=='0')s=s.substr(0,i);else break;
			n=s.size();
			if(s[n-1]=='.')s=s.substr(0,s.size()-1);
		}
	for(int i=0;i<n;i++)if(s[i]=='.'){a=i;break;}
	for(int i=a+1;i<n;i++)if(s[i]>='5'){cnt=i;break;}
	if(cnt==-1){
		cout<<s;
		return 0;
	}
	for(;s[cnt]!='.'&&s[cnt]>='4'&&k>0;k--,cnt--);
	s=s.substr(0,cnt+1);
	if(s[s.size()-1]=='.')s=s.substr(0,s.size()-1);
	s[s.size()-1]++;
	int i=s.size()-1; 
	while(!isdigit(s[i])&&i)s[i]='0',s[i-1]++,i--;
	if(!isdigit(s[0]))s[0]='0',s='1'+s;
	cout<<s;
}