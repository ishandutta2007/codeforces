#include <bits/stdc++.h>
using namespace std;
#define int long long int
main() {
	int n;
	cin>>n;
	int x[n];
	int y[n];
	int z[n];
	bool ex[n];
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i]>>z[i];
		ex[i]=1;
	}
	int cnt=0;
	for(int i=0; i<n; i++){
		int index=-1;
		int mini=1000000000000000000;
		if(cnt==(n/2)){
			return 0;
		}
		if(ex[i]==0){
			continue;
		}
		for(int j=i+1; j<n; j++){
			if(ex[j]==0){
				continue;
			}
			int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
			if(dis<mini){
				index=j;
				mini=dis;
			}
		}
		ex[i]=0;
		ex[index]=0;
		cout<<i+1<<" "<<index+1<<endl;
		cnt++;
	}
	return 0;
}