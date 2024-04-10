#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s1[203],s2[203];
map<string,int>mp1,mp2;
int main()
{
	cin>>n;
	mp1.clear();
	mp2.clear();
	for(int i=0;i<n;i++)
		cin>>s1[i],
		mp1[s1[i]]++;
	for(int i=0;i<n;i++)
		cin>>s2[i],
		mp2[s2[i]]++;
	ans+=fabs(mp1["M"]-mp2["M"]);
	ans+=fabs(mp1["S"]-mp2["S"]);
	ans+=fabs(mp1["L"]-mp2["L"]);
	ans+=fabs(mp1["XL"]-mp2["XL"]);
	ans+=fabs(mp1["XS"]-mp2["XS"]);
	ans+=fabs(mp1["XXL"]-mp2["XXL"]);
	ans+=fabs(mp1["XXS"]-mp2["XXS"]);
	ans+=fabs(mp1["XXXL"]-mp2["XXXL"]);
	ans+=fabs(mp1["XXXS"]-mp2["XXXS"]);
	cout<<ans/2;
}