#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,c0,c1,h,ans=0;
		string s;
		cin>>n>>c0>>c1>>h>>s;
		for(int i=0;i<n;i++)
			if(s[i]=='0')
				ans+=min(c0,c1+h);
			else
				ans+=min(c1,c0+h);
		cout<<ans<<endl;
	}
}