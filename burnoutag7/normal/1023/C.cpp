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
int n,k;
string s;
stack<int> st;
vector<pair<int,int> > v;
bool out[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			st.push(i);
		}else{
			v.push_back(make_pair(st.top(),i));
			st.pop();
		}
	}
	for(int i=0;i<k/2;i++){
		out[v[i].first]=1;
		out[v[i].second]=1;
	}
	for(int i=0;i<s.size();i++){
		if(out[i]){
			cout<<s[i];
		}
	}
	return 0;
}