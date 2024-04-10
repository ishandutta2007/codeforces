/******************
*  Writer: Oh no  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int ttt;
	cin>>ttt;
	while(ttt--){
		
		string s;
		cin>>s;
		
		int tot=0;
		for(int i=0;i<s.size();i++){
			if(s[i]==':')tot++;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]==':'){
				if(s[i+1]==':'){
					while(tot<7){
						tot++;
						s=s.substr(0,i+1)+':'+s.substr(i+1,s.size()-i-1);
					}
					while(tot>7){
						tot--;
						s=s.substr(0,i)+s.substr(i+1,s.size()-i-1);
					}
					break;
				}
			}
		}//7 
		
		s=':'+s+':';// 
		
		//cout<<"DEBUG  "<<s<<endl;
		
		for(int i=0;i<s.size()-1;i++){
			if(s[i]==':'){
				int j;
				for(j=i+1;s[j]!=':';j++);
				while(j-i-1<4){
					j++;
					s=s.substr(0,i+1)+'0'+s.substr(i+1,s.size()-i-1);
				}
			}
		}
		
		cout<<s.substr(1,39)<<endl;
	}
	return 0;
}