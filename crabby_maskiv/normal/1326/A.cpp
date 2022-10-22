#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001;
int n,m;
int main(){
	int i,j,k;
	int T;cin>>T;
	while(T--){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else{
			for(i=1;i<n;i++) cout<<9;
			cout<<8<<endl;
		}
	}
	return 0;
}