#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		string s;cin>>s>>s;int cnt=0,res=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==')')cnt++;
			else cnt--;
			res=max(res,cnt);
		}cout<<res<<endl;
	}
}