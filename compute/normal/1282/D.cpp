#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"a"<<endl;
	int len,tmp;
	cin>>len;
	if(!len) return 0;
	len++;
	string s;
	for(int i=0;i<300;i++) s+='a';
	cout<<s<<endl;
	cin>>tmp;
	if(!tmp) return 0;
	int cnta,cntb;
	cnta=300-tmp;
	if(cnta==0)
		len--,cntb=len;
	else cntb=len-cnta;
	string ans;
	for(int i=0;i<len;i++) ans+='a';
	for(int i=0;i<len-1;i++)
	{
		ans[i]='b';
		cout<<ans<<endl;
		cin>>tmp;
		if(!tmp) return 0;
		if(tmp>=cntb) ans[i]='a';
		else cntb=tmp;
	}
	if(cntb) ans[len-1]='b';
	cout<<ans<<endl;
	cin>>tmp;
	assert(tmp==0);
}