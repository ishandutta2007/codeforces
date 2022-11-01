#include<iostream>
#include<vector>
using namespace std;
#define R register int
int a[200001],ct[200001];
inline void Solve(){
	int n,k;
	cin>>n>>k;
	for(R i=1;i<=n;i++){
		cin>>a[i];
		ct[i]=0;
	}
	for(R i=1;i<=n;i++){
		ct[a[i]]++;
	}
	int l=0,sum=-n,ans=n,ansl,ansr;
	for(R i=1;i<=n;i++){
		sum+=ct[i]<<1;
		while(sum-(ct[l]<<1)>=k){
			sum-=ct[l]<<1;
			l++;
		}
		if(sum>=k&&i-l<ans){
			ans=i-l;
			ansl=l;
			ansr=i;
		}
	}
	cout<<ansl<<" "<<ansr<<endl;
	int pre=0,prel=1;
	vector<pair<int,int>>V;
	for(int i=1;i<=n;i++){
		pre+=a[i]>=ansl&&a[i]<=ansr?1:-1;
		if(pre==1){
			V.push_back(make_pair(prel,i));
			prel=i+1;
			pre=0;
		}
	}
	for(R i=0;i!=k-1;i++){
		cout<<V[i].first<<" "<<V[i].second<<endl;
	}
	cout<<V[k-1].first<<" "<<n<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}