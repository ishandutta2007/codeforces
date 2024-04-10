#include <bits/stdc++.h>
using namespace std;


int main() {
	long long int n, p, w, d;
	cin>>n>>p>>w>>d;
	for(int i=0; i<w; i++){
		if((p-d*i)%w==0 && (p-d*i>=0)){
			long long int val=i+((p-d*i)/w);
			if(val<=n){
				cout<<(p-d*i)/w<<" "<<i<<" "<<n-i-((p-d*i)/w);
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}