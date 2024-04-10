#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli mod=998244353;
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
lli fact(lli a){
	lli prod=1;
	for(lli i=1;i<=a;i++){
		prod=prod*i%mod;
	}
	return prod;
}
struct secsort{
	bool operator()(const pii& lhs, const pii& rhs)const {
		if(lhs.second==rhs.second)return lhs.first<rhs.first;
		return lhs.second<rhs.second;
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    pii arr[n];
    lli ans=fact(n);
    for(lli i=0;i<n;i++){
    	cin>>arr[i].first>>arr[i].second;
    }

    sort(arr,arr+n);
	int chain=1;
	vector<int> chains;
	for(int i=1;i<n;i++){
		if(arr[i].first==arr[i-1].first){
			chain+=1;
		}
		else{
			chains.push_back(chain);
			chain=1;
		}
	}
	chains.push_back(chain);
	lli tot=1;
	for(int x:chains){
		tot=tot*fact(x)%mod;
	}
	ans=make(ans-tot);

	sort(arr,arr+n,secsort());
	chain=1;
	chains.clear();
	for(int i=1;i<n;i++){
		if(arr[i].second==arr[i-1].second){
			chain+=1;
		}
		else{
			chains.push_back(chain);
			chain=1;
		}
	}
	chains.push_back(chain);
	tot=1;
	for(int x:chains){
		tot=tot*fact(x)%mod;
	}
	ans=make(ans-tot);

	sort(arr,arr+n);
	chain=1;
	chains.clear();
	bool work=true;
	for(int i=1;i<n;i++){
		if(arr[i].second==arr[i-1].second&&arr[i].first==arr[i-1].first){
			chain+=1;
		}
		else if(arr[i].second<arr[i-1].second||arr[i].first<arr[i-1].first){
			work=false;
		}
		else{
			chains.push_back(chain);
			chain=1;
		}
	}
	chains.push_back(chain);
	if(work) {
		tot = 1;
		for (int x:chains) {
			tot = tot * fact(x) % mod;
		}
		ans = make(ans + tot);
	}
	printf("%lli\n",ans);
    return 0;
}