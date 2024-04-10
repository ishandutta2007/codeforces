#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int x[maxn],y[maxn];
int n,a,b;
int mxoc;

int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b)||(x[i]+y[j]<=a&&y[i]<=b&&x[j]<=b)||(y[i]+x[j]<=a&&x[i]<=b&&y[j]<=b)||(y[i]+y[j]<=a&&x[i]<=b&&x[j]<=b)||(x[i]+x[j]<=b&&y[i]<=a&&y[j]<=a)||(x[i]+y[j]<=b&&y[i]<=a&&x[j]<=a)||(y[i]+x[j]<=b&&x[i]<=a&&y[j]<=a)||(y[i]+y[j]<=b&&x[i]<=a&&x[j]<=a))mxoc=max(mxoc,x[i]*y[i]+x[j]*y[j]);
		}
	}
	cout<<mxoc;
	return 0;
}