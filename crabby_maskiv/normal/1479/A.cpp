#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int main(){
	int i,j;
	cin>>n;
	int l=1,r=n;
	while(l<r){
		int a,b,c;
		int x=l+r>>1;
		if(x>1){
			cout<<"? "<<x-1<<endl;
			fflush(stdout);
			cin>>a;
		}
		else a=n+1;
		cout<<"? "<<x<<endl;
		fflush(stdout);
		cin>>b;
		if(x<n){
			cout<<"? "<<x+1<<endl;
			fflush(stdout);
			cin>>c;
		}
		else c=n+1;
		if(b<a&&b<c){
			cout<<"! "<<x<<endl;
			return 0;
		}
		else if(a<b) r=x-1;
		else l=x+1;
	}
	cout<<"! "<<l;
	fflush(stdout);
	return 0;
}