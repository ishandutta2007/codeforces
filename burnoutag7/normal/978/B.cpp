#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int n,i=0,cnt=0;
int main(){
	cin>>n;
	cin>>s;
	while(i<s.size()-2){
		if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
			s.erase(i,1);
			cnt++;
		}else{
			i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}