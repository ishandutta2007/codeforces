#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,x,y;
int main(){
	cin>>a>>b>>c>>d>>x>>y;c-=a;d-=b;
	if(c%x==0 && d%y==0 && (abs(c)/x+abs(d)/y)%2==0){cout<<"YES"<<endl;}
	else cout<<"NO"<<endl;
	return 0;
}