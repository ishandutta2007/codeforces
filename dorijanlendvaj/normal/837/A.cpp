#include <bits/stdc++.h>

using namespace std;

string h;
int n,vol,temp;
char e;

bool capi(char a)
{
	if (a<='Z' && a>='A') return true;
	return false;
}

int main()
{
	cin>>n>>e;
	getline(cin,h);
	temp+=capi(e);
	for (int i=0;i<n-1;++i)
	{
		if (capi(h[i])) ++temp;
		if (h[i]==' ')
		{
			vol=max(vol,temp);
			temp=0;
		}
	}
	cout<<max(vol,temp)<<endl;
}