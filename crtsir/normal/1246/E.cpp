#include<bits/stdc++.h>
using namespace std;
int n,k,a[23];
pair<int,int>opt[16];
vector<int>v;
int main(){
	srand(time(NULL));
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	double fr=clock();
	while((clock()-fr)/CLOCKS_PER_SEC<1.9){
		v.clear();
		for(int i=0;i<n;i++)
			v.push_back(a[i]);
		for(int i=0;i<n-1;i++){
			int l=rand()%(v.size()-1),r=rand()%(v.size()-l-1)+l+1,x=v[l]+v[r];
			opt[i]={v[l],v[r]};
			v.erase(v.begin()+r);
			v.erase(v.begin()+l);
			while(x%k==0)x/=k;
			v.push_back(x);
		}
		if(v[0]==1){
			cout<<"YES\n";
			for(int i=0;i<n-1;i++)
				printf("%d %d\n",opt[i].first,opt[i].second);
			return 0;
		}
	}
	cout<<"NO\n";
}