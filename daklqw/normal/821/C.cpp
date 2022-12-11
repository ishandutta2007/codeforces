#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans,t,la=1;char str[10];
int main(){
	vector<int>s;
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>str;
		if(str[0]=='a'){cin>>t;s.push_back(t);}
		else{
			if(!s.empty()){if(s.back()!=la){s.clear();++ans;}else s.pop_back();}
			++la;
		}
	}
	cout<<ans<<endl;
	return 0;
}