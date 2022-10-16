#include<bits/stdc++.h>
using namespace std;
string s,ans;
bool del[100010];
int i,lst;
int main(){
	cin>>s;
	for(char c='a';c<='z';c++){
		for(i=lst-1;i>=0&&(s[i]<=c||del[i]);i--)
			if(!del[i]){
				ans+=s[i];
				del[i]=1;
			}
		for(int i=lst;i<s.size();i++)
			if(s[i]==c){
				ans+=c;
				del[i]=1;
				lst=i;
			}
	}
	for(int i=s.size()-1;i>=0;i--)
		if(!del[i])
			ans+=s[i];
	cout<<ans;
	return 0;
}