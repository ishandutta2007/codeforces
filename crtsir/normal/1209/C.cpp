#include<bits/stdc++.h>
using namespace std;
string s;
int n,t;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		int i;
		for(i=0;i<10;i++)
		{ 
			int max1=0,max2=0;
			string ans;
			ans=""; 
			for(int j=0;j<n;j++)
				if(s[j]-'0'<i)
					if(max1>s[j]-'0')
						break;
					else
						max1=s[j]-'0',
						ans+='1';
				else
					if(s[j]-'0'>i)
						if(max2>s[j]-'0')
							break;
						else
							max2=s[j]-'0',
							ans+='2';
					else
						if(max2>s[j]-'0')
							ans+='1',
							max1=s[j]-'0';
						else
							ans+='2';
			if(ans.size()==n)
			{
				cout<<ans<<endl;
				break;
			}
		} 
		if(i==10)cout<<'-'<<endl;
	}
}