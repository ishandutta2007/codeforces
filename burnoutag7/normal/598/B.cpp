/*
abacaba
2
3 6 1
1 4 2

baabcaa
*/
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
int m,len;
int l,r,k;
string s;
string rev(string t,int x,int y){
	string res;
	for(int i=y;i>=x;i--){
		res+=t[i-1];
	}
	cout<<res<<endl;
	return res;
}
int main(){
	cin>>s;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>k;
		len=r-l+1;
		k%=len;
		s=s.substr(0,l-1)+s.substr(r-k,k)+s.substr(l-1,len-k)+s.substr(r,s.size()-r+1);
	}
	cout<<s<<endl;
	return 0;
}