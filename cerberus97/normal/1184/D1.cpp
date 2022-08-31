#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,m,t, cur = 1;
	cin>>n>>k>>m>>t; k--;
	int st = 0, en = n-1, sz = n;
	vector<int> v;
	for(int i=0;i<n;i++) v.push_back(cur++);
	while(t--){
		int q, val; cin>>q>>val;
		val--;
		if(q){
			v.insert(v.begin() + st+val, cur++);
			en++;
			if(st+val <= k) k++;
			sz++;
			cout<<sz<<" "<<k-st+1<<endl;
		}
		else{
			if(st+val >= k){
				en = st+val;
				sz = en-st+1;
				cout<<sz<<" "<<k-st+1<<endl;
			}
			else{
				st = st + val + 1;
				sz = en-st+1;
				cout<<sz<<" "<<k-st+1<<endl;
			}
		}
	}
	return 0;
}