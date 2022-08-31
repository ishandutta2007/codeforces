#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char>st;
char p[128];
int main(){
	int ans=0;
	string s;
	cin>>s;
	p[')']='(';p[']']='[';p['}']='{';p['>']='<';
	for(int k=0;k<s.length();k++){
		if(p[s[k]]){
			if(st.empty()){
				cout<<"Impossible";
				return 0;
			}
			if(st.top()!=p[s[k]])ans++;
			st.pop();
		}
		else st.push(s[k]);
	}
	if(st.empty())cout<<ans;
	else cout<<"Impossible";
	return 0;
}