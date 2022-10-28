#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<string> st;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		string s2="";
		int cnt=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='k'){
				cnt++;
			}else if(s[i]=='h'){
				cnt=0;
				s2+=s[i];
			}else{
				while(cnt>0){
					s2+='k';
					cnt--;
				}
				if(s[i]=='u'){
					s2+="oo";
				}else{
					s2+=s[i];
				}
			}
		}
		while(cnt>0){
			s2+='k';
			cnt--;
		}
		st.insert(s2);
	}
	cout<<st.size()<<endl;
}