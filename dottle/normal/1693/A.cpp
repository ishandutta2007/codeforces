#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> A(n);
	for(auto&x:A)cin>>x;
	while(A.size()&&A.back()==0)A.pop_back();
	int s=0;
	for(int i=0;i<A.size();i++){
		int x=A[i];
		s+=x;
		if(s<=0&&i+1!=A.size()){
			cout<<"no"<<endl;
			return;
		}
	}
	if(s!=0)cout<<"no"<<endl;
	else cout<<"yes"<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}