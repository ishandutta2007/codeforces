#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
const int N = 123;
int n,m;
int vec[N];
int sec[N];
string s[N];
map<string,int>mp;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	sort(vec,vec+n);
	for(int i=0;i<m;i++)
	{
		cin>>s[i];
		mp[s[i]]++;
	}
	sort(s,s+m);
	m = unique(s,s+m) - s;
	for(int i=0;i<m;i++)
	{
		sec[i] = mp[s[i]];
	}
	sort(sec,sec+m);
	int x = 0;
	int y = 0;
	for(int i=m-1;i>=0;--i)
	{
		x += sec[i]*vec[m-i-1];
	}
	for(int i=0;i<m;i++)
	{
		y += sec[i]*vec[n-(m-i)];
	}
	cout<<x<<" "<<y<<endl; 
	return 0;
}