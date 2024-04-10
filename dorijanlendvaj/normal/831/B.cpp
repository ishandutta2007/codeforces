#include <bits/stdc++.h>

using namespace std;

bool broj(char a)
{
	if (a>'9') return false;
	return true;
}

string a,b;
string h;
map<char,char> tran;
int n=26;

int main()
{
	std::cin.sync_with_stdio(false);
	cin>>a>>b>>h;
	for (int i=0;i<n;++i)
	{
		tran[a[i]]=b[i];
		tran[a[i]+'A'-'a']=b[i]+'A'-'a';
	}
	for (int i=0;i<h.size();++i)
	{
		if (broj(h[i])) cout<<h[i];
		else cout<<tran[h[i]];
	}
	cout<<endl;
}