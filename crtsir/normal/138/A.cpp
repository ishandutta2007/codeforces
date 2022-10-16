#include<bits/stdc++.h>
using namespace std;
int n,k;
string s[4];
bool can[3]={1,1,1};
bool isy(char c){
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>s[j];
			int cnt=0,num=s[j].size()-1;
			while(cnt<k&&num>=0)cnt+=isy(s[j][num--]);
			if(cnt<k){
				cout<<"NO";
				return 0;
			}
			s[j]=s[j].substr(num+1);
		}
		if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])continue;
		if(s[0]==s[1]&&s[2]==s[3]){can[1]=0,can[2]=0;continue;}
		if(s[0]==s[2]&&s[1]==s[3]){can[0]=0,can[2]=0;continue;}
		if(s[0]==s[3]&&s[1]==s[2]){can[0]=0,can[1]=0;continue;}
		{cout<<"NO";return 0;}
	}
	if(can[0]&&can[1]&&can[2]){
		cout<<"aaaa";
		return 0;
	}
	if(can[0]){
		cout<<"aabb";
		return 0;
	}
	if(can[1]){
		cout<<"abab";
		return 0;
	}
	if(can[2]){
		cout<<"abba";
		return 0;
	}
	cout<<"NO";
}