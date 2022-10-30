#include<bits/stdc++.h>
const int N=350000;

using namespace std;

vector<pair<int,int> > p(N);


int t,n,m;
main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans=0;
		for(int i=0;i<n*m;i++){
			int x;
			cin>>x;
			p[i]=make_pair(x,i);
		}
		sort(p.begin(),p.begin()+n*m);
		for(int i=0;i<n*m;i++)
			p[i].second*=-1;
		for(int i=0;i<n;i++){
			sort(p.begin()+(m*i),p.begin()+(m*i+m));
			for(int j=0;j<m;j++)
				for(int k=0;k<j;k++)
					if(p[i*m+k].second>p[i*m+j].second)
						ans++;
		}
		cout<<ans<<endl;
	}
}