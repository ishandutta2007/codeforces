#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, x, y;
		cin>>n>>x>>y;
		int gap=y-x;
		int mini=1e18;
		int diff=0;
		for(int i=1; i<=50; i++){
			if(gap%i!=0){
				continue;
			}
			if((gap/i)+1>n){
				continue;
			}
			int num=n;
			num-=((gap/i)+1);
			int xx=x;
			while(num!=0){
				if(xx-i>0){
					xx=xx-i;
					num--;
				}
				else{
					break;
				}
			}
			int yy=y+num*i;
			if(yy<mini){
				mini=yy;
				diff=i;
			}
		}
		vector<int>v;
		int num=x;
		v.pb(num);
		while(num!=y){
			num=num+diff;
			v.pb(num);
		}
		int rem=n-((gap/diff)+1);
		int xx=x;
		while(rem!=0){
			if(xx-diff>0){
				xx-=diff;
				v.pb(xx);
				rem--;
			}
			else{
				break;
			}
		}
		int yy=y;
		while(rem!=0){
			v.pb(yy+diff);
			yy+=diff;
			rem--;
		}
		for(auto u:v){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}