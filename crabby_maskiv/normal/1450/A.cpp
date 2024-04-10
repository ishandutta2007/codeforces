#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		string a;cin>>a;
		string b;
		for(i=0;i<n;i++) if(a[i]=='b') b.push_back('b');
		for(i=0;i<n;i++) if(a[i]!='b') b.push_back(a[i]);
		cout<<b<<endl;
	}
	return 0;
}