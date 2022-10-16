#include<bits/stdc++.h>
using namespace std;
int can;
string s;
char yf;
int main(){
	cin>>s>>s;
	for(int i=0;i<s.size();i++)if(s[i]=='W')can++;
	if(can%2&&(s.size()-can)%2){
		cout<<-1;
		return 0;
	}
	vector<int>ans;
	if(can%2==0)yf='B';else yf='W';can=0;
	for(int i=0;i<s.size();i++){
		if(can%2)ans.push_back(i); 
		if(s[i]!=yf)can++;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' '; 
}