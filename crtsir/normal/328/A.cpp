#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a&&b&&c&&d)
		if(a*1.0/b==b*1.0/c&&b*1.0/c==c*1.0/d){
			double ans=d*d*1.0/c;
			if(d*d%c==0)
			{
				cout<<ans;
				return 0;
			}
		}
	if(a-b==b-c&&b-c==c-d){
		int ans=d+d-c;
		cout<<ans;
		return 0;
	}
	cout<<42;
}