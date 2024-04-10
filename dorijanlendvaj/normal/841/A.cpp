#include <bits/stdc++.h>

using namespace std;

int n,k;
string h;
map<char,int> b;
int ma;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k>>h;
	for (int i=0;i<h.size();++i) ++b[h[i]];
	for (map<char,int>::iterator it=b.begin();it!=b.end();++it) ma=max(ma,it->second);
	if (ma<=k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}