#include <bits/stdc++.h>

using namespace std;

bool pal[5001][5001];
vector<pair<short,short> > pali;
string h;
int cara[5001],br1;
int sv[5001][5001];

int prov(int a,int b)
{
	if (a==b) return 1;
	if (sv[a][b]) return sv[a][b];
	if (!pal[a][b])
	{
		sv[a][b]=0;
		return 0;
	}
	sv[a][b]=1+min(prov(a,(b+a-1)/2),prov(b-(b-a-1)/2,b));
	return sv[a][b];
}

int main()
{
	cin>>h;
	int n=h.size();
	for (short i=0;i<n-1;++i)
	{
		short a=i,b=i+1;
		while (a>=0 && b<n && h[a]==h[b])
		{
			pal[a][b]=true;
			++br1;
			pali.push_back(make_pair(a,b));
			--a;
			++b;
		}
	}
	for (short i=0;i<n;++i)
	{
		pal[i][i]=true;
		short a=i-1,b=i+1;
		while (a>=0 && b<n && h[a]==h[b])
		{
			pal[a][b]=true;
			++br1;
			pali.push_back(make_pair(a,b));
			--a;
			++b;
		}
	}
	for (int i=0;i<pali.size();++i)
	{
		int du=prov(pali[i].first,pali[i].second);
		for (int j=0;j<du;++j) ++cara[j];
	}
	cout<<cara[0]+n<<' ';
	for (int i=1;i<n;++i) cout<<cara[i]<<' ';
	cout<<endl;
	//cout<<pali.size()<<endl;
}