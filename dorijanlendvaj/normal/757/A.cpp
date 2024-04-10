#include <bits/stdc++.h>

using namespace std;

string a;
vector<int> kol;

int mi(vector<int> e)
{
	int h=min(e[0],e[1]);
	h=min(min(h,e[2]),e[3]);
	h=min(min(h,e[4]/2),e[5]);
	h=min(min(h,e[6]/2),e[7]);
	return h;
}

int main()
{
	cin>>a;
	kol.resize(10);
	for (int i=0;i<a.size();++i)
	{
		if (a[i]=='B') ++kol[0];
		if (a[i]=='u') ++kol[1];
		if (a[i]=='l') ++kol[2];
		if (a[i]=='b') ++kol[3];
		if (a[i]=='a') ++kol[4];
		if (a[i]=='s') ++kol[5];
		if (a[i]=='u') ++kol[6];
		if (a[i]=='r') ++kol[7];
	}
	cout<<mi(kol)<<endl;
}