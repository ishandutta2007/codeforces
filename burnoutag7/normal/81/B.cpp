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
char buf[500];
string s;
vector<string> v;

bool di(char c){
	return c>='0'&&c<='9';
}

int main(){
	gets(buf);
	s=buf;
	for(int i=0;i<s.size();i++){
		if(s[i]==','){
			v.push_back(",");
		}else{
			if(s[i]=='.'){
				v.push_back("...");
				i+=2;
			}else{
				if(di(s[i])){
					string t;
					for(int j=i;j<s.size();j++){
						if(di(s[j])){
							t+=s[j];
						}else{
							break;
						}
					}
					v.push_back(t);
					i+=t.size()-1;
				}
			}
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i][0]==','){
			cout<<",";
			if(i<v.size()-1){
				cout<<' ';
			}
		}else{
			if(v[i][0]=='.'){
				cout<<v[i];
				if(i<v.size()-1){
					if(v[i+1][0]=='.'){
						cout<<' ';
					}
				}
			}else{
				cout<<v[i];
				if(i<v.size()-1){
					if(di(v[i+1][0])||v[i+1][0]=='.'){
						cout<<' ';
					}
				}
			}
		}
	}
	return 0;
}