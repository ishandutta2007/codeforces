#include <iostream>
using namespace std;
int s,v1,v2,t1,t2;
int x,y;
int main()
{
	cin>>s>>v1>>v2>>t1>>t2;
	x=s*v1+2*t1;
	y=s*v2+2*t2;
	if (x<y)cout<<"First"<<endl;
	else 
	if (x>y)cout<<"Second"<<endl;
	else cout<<"Friendship"<<endl;
}