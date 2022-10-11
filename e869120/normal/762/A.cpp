#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,k;vector<long long>v;
int main(){
	cin>>n>>k;k--;
	for(long long i=1;i*i<=n;i++){
		if(n%i!=0)continue;
		v.push_back(i);if(i!=(n/i))v.push_back(n/i);
	}
	sort(v.begin(),v.end());
	if(k>=v.size())cout<<"-1"<<endl;
	else cout<<v[k]<<endl;
	return 0;
}