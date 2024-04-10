#include<bits/stdc++.h>
using namespace std;
int n,a,b;
const int MAX = 200;
int x[MAX],y[MAX];
int ans =0;
void maxx(int x1,int y1,int x2,int y2){
	if (x1+x2<=a&&y1<=b&&y2<=b){
		ans = max(ans,x1*y1+x2*y2);
	}
	if (x1<=a&&x2<=a&&y1+y2<=b){
		ans = max(ans,x1*y1+x2*y2);
	}
}
int main(){
	cin>>n>>a>>b;
	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			maxx(x[i],y[i],x[j],y[j]);
			maxx(x[i],y[i],y[j],x[j]);
			maxx(y[i],x[i],x[j],y[j]);
			maxx(y[i],x[i],y[j],x[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}