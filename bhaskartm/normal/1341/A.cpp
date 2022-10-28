#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n, a, b, c, d;
		cin>>n>>a>>b>>c>>d;
		if((n*(a-b)<(c-d) && (n*(a+b))<(c-d)) || (n*(a-b)>(c+d) && (n*(a+b))>(c+d))){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}