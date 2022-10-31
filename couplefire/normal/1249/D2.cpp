//https://codeforces.com/problemset/problem/1249/D2

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<pair<int,int> >v[200005];
set<pair<int,int> >st;
vector<int>ans;
int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		v[l].push_back(make_pair(r,i));
	}
 	for(int i=1;i<=200000;i++)
 	{
 		while(!st.empty()&&(*st.begin()).first<i)st.erase(*st.begin());
 		for(int j=0;j<v[i].size();j++)
 		{
 			st.insert(v[i][j]);
		 }
		while(st.size()>k)
		{
			ans.push_back((*st.rbegin()).second);
			st.erase((*st.rbegin()));
		}
	 }
	 int len=ans.size();
	 cout<<len<<endl;
	 for(int i=0;i<len;i++)
	 	cout<<ans[i]<<" ";
	 cout<<endl;
  return 0;
}