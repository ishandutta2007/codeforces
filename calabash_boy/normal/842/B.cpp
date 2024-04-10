#include<bits/stdc++.h>
using namespace std;
int n;
double r,d;
int main(){
	cin>>r>>d;
	int ans =0;
	cin>>n;
	while (n--){
		int x,y,ri;
		scanf("%d%d%d",&x,&y,&ri);
		long long dist = x*x+y*y;
		long long mx = (r-ri)*(r-ri);
		long long mn = (r-d+ri)*(r-d+ri);
		if (dist>=mn&&dist<=mx){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}