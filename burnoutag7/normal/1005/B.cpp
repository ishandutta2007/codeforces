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
string s,t;
int main(){
	cin>>s>>t;
	int i;
	for(i=0;s[s.size()-1-i]==t[t.size()-1-i] && s.size()-1-i>=0 && t.size()-1-i>=0;i++) if(s.size()-i+t.size()-i==0) break;
	cout<<s.size()-i+t.size()-i;
	return 0;
}