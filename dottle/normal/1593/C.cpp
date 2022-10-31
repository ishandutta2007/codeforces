#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

void solve(){
	int n,l;
	cin>>l>>n;
	
	vector<int> a(n+5),b;
	for(int i=1;i<=n;i++)
		cin>>a[i],b.push_back(l-a[i]);
	if(l==2){
		cout<<1<<endl;
		return ;
	}
	sort(b.begin(),b.end());
	for(int i=0,s=0;i<b.size();i++){
		s+=b[i];
		if(s>=l){
			cout<<i<<endl;
			return ;
		}
	}
	cout<< n <<endl;
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}