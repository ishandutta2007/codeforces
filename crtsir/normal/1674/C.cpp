#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		string s,t;
		cin>>s>>t;
		bool ok1=0,ok2=0;int cntt=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='a')
				ok1=1,cntt++;
		for(int i=0;i<t.size();i++)
			if(t[i]=='a')
				ok2=1;
		if(t=="a"||!ok1)
			cout<<1<<endl;
		else
			if(ok2)
				cout<<-1<<endl;
			else
				cout<<(1ll<<cntt)<<endl;
	}
}