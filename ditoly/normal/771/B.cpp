#include<iostream>
using namespace std;
#define MN 50
int f[MN+5],t[MN+5];
string build(int x)
{
	string s=x<26?"A":"B";
	return s+=x%26+'a';
}
int main()
{
	int n,k,i;string s;
	cin>>n>>k;
	for(i=1;i<n;++i)f[i]=i;
	for(i=0;i<n-k+1;++i)cin>>s,t[i]=s=="NO";
	while(i--)if(t[i])f[i]=f[i+k-1];
	for(i=0;i<n;++i)cout<<build(f[i])<<' ';
}