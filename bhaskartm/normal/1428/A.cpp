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
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2 || y1==y2){
			cout<<abs(x1-x2)+abs(y1-y2)<<endl;
		}
		else{
				cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
		}
	}
	return 0;
}