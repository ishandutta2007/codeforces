#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		if(m>(n+1)/2){
			cout<<-1<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j&&(i&1)&&(i+1)/2<=m) cout<<"R";
				else cout<<".";
			}
			cout<<endl;
		}
	}
	return 0;
}