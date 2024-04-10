#include<bits/stdc++.h>
using namespace std;

int t,n;
string a[2];

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>a[0]>>a[1];
		int fl=1;
		for(int i=0;i<n;i++)if(a[0][i]=='1'&&a[1][i]=='1')fl=0;
		cout<<(fl?"YES":"NO")<<endl;
	}
}