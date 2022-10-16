#include<bits/stdc++.h>
using namespace std;
string s,as;
int a[10003],len;
int main(){string ask="";
	cin>>as;len=as.size();
	for(int i=0;i<len;i++)
		ask+=char(i/676+'a');
	cout<<"? "<<ask<<endl;cin>>s;
	for(int i=0;i<len;i++)
		a[i]+=(s[i]-'a')*676;ask="";
	for(int i=0;i<len;i++)
		ask+=char((i/26)%26+'a');
	cout<<"? "<<ask<<endl;cin>>s;
	for(int i=0;i<len;i++)
		a[i]+=(s[i]-'a')*26;ask="";
	for(int i=0;i<len;i++)
		ask+=char(i%26+'a');
	cout<<"? "<<ask<<endl;cin>>s;
	for(int i=0;i<len;i++)
		a[i]+=s[i]-'a';
	cout<<"! ";
	for(int i=0;i<len;i++)
		ask[a[i]]=as[i];
	cout<<ask;
}