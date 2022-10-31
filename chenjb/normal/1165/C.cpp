#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
string s,t;
int main()
{
	int n; cin>>n;
	cin>>s;
	t="";
	for(int i=0;i<n;i++)
		if (t.length()%2==1 && t.back()!=s[i])t+=s[i];
		else if (t.length()%2==0)t+=s[i];
	if (t.length()%2==1)t.pop_back();
	cout<<s.length()-t.length()<<endl;
	cout<<t<<endl;
}