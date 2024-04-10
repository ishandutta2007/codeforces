#include <bits/stdc++.h>

using namespace std;

int n,rj;
vector<int> h;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	n*=2;
	rj=100000001;
	h.resize(n);
	//cout<<"Tu sam"<<' '<<n<<endl;
	for (int i=0;i<n;++i) cin>>h[i];
	//cout<<"Tu sam."<<endl;
	sort(h.begin(),h.end());
	//cout<<"Tu sam."<<endl;
	for (int i=0;i<n;++i)
	{
		int ki=h[i];
		h.erase(h.begin()+i);
		for (int j=0;j<n-1;++j)
		{
			int kj=h[j];
			h.erase(h.begin()+j);
			//cout<<ki<<' '<<kj<<endl;
			//for (int k=0;k<n-2;++k) cout<<h[k]<<' ';
			//cout<<endl;
			int temp=0;
			for (int k=0;k<n-2;k+=2) temp+=h[k+1]-h[k];
			rj=min(rj,temp);
			//cout<<temp<<endl<<endl;
			h.insert(h.begin()+j,kj);
		}
		h.insert(h.begin()+i,ki);
	}
	cout<<rj<<endl;
}