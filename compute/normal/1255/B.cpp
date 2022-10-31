#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1);
		int tot=0;
		for(int i=1;i<=n;i++) cin>>a[i],tot+=a[i];
		if(m!=n||n==2) cout<<-1<<'\n';
		else{
			cout<<tot*2<<'\n';
			for(int i=1;i<=n;i++){
				cout<<i<<" "<<i%n+1<<'\n';
			}
		}

	}
}