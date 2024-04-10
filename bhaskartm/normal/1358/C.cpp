#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

 main() {
	int t;
	cin>>t;
	while(t--){
		 int x1, y1, x2, y2;
		 cin>>x1>>y1>>x2>>y2;
		 cout<<(x2-x1+y2-y1)*(x2-x1)-(x2-x1)*(x2-x1)+1<<endl;
	}
	return 0;
}