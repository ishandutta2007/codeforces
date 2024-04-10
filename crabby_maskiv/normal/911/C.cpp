#include<iostream>
using namespace std;
int a,b,c;
bool ans;
int main()
{
	cin>>a>>b>>c;
	if(a==1||b==1||c==1) ans=1;
	if((a==2&&b==2)||(b==2&&c==2)||(a==2&&c==2)) ans=1;
	if(a==3&&b==3&&c==3) ans=1;
	if((a==2&&b==4&&c==4)||(a==4&&b==2&&c==4)||(a==4&&b==4&&c==2)) ans=1;
	if(ans==1) cout<<"YES";
	else cout<<"NO";
	return 0;
}