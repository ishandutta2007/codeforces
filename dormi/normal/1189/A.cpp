#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string a;
	cin>>a;
	int count=0;
	for(int i=0;i<n;i++){
		count+=(a[i]=='1'?1:-1);
	}
	if(count==0){
		cout<<"2\n"<<a.substr(0,n-1)<<" "<<a.substr(n-1,1)<<"\n";
	}
	else{
		cout<<"1\n"<<a<<"\n";
	}
	return 0;
}