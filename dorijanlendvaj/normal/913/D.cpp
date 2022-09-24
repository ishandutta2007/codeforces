#include <bits/stdc++.h>

using namespace std;

int n,t;
pair<int,pair<int,int> > a[200001];

pair<bool,int> ch(int k,bool is)
{
	int ts=0,ps=0;
	vector<int> u;
	for (int i=0;i<n && ps<k && ts<=t;++i)
	{
		if (a[i].second.first<k) continue;
		++ps;
		ts+=a[i].first;
		u.push_back(a[i].second.second+1);
	//	cout<<i<<' '<<n<<' '<<ps<<' '<<k<<' '<<ts<<' '<<t<<endl;
	}
	if (ts>t)
	{
		ts-=a[u[u.size()-1]].first;
		--ps;
	}
	//cout<<ts<<' '<<ps<<' '<<k<<endl;
	if (ps<k) return {0,ps};
	if (is)
	{
		cout<<k<<endl<<k<<endl;
		for (int i=0;i<u.size();++i) cout<<u[i]<<' ';
		cout<<endl;
	}
	return {1,ps};
}

void bis(int lo,int hi)
{
	if (lo==hi)
	{
		ch(lo,1);
		return;
	}
	else if (lo==hi-1)
	{
		//cout<<lo<<' '<<hi<<endl;
		if (!ch(hi,1).first) ch(lo,1);
		return;
	}
	int mid=(lo+hi)/2;
	pair<bool,int> kl=ch(mid,0);
	if (kl.second<mid) bis(lo,mid-1);
	else bis(mid,hi);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>t;
	for (int i=0;i<n;++i)
	{
		cin>>a[i].second.first>>a[i].first;
		a[i].second.second=i;
	}
	sort(a,a+n);
	bis(0,n);
}