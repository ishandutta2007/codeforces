#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;


int n,k;
int a[maxn];

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		int mxi=0,miv=0x7fffffff;
		for(int i=1;i<=n-k;i++){
			int tsp=(a[i+k]-a[i]+1)/2;
			if(tsp<miv){
				miv=tsp;
				mxi=(a[i+k]+a[i])/2;
			}
		}	
		cout<<mxi<<'\n';
	}
    return 0;
}