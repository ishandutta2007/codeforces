#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	long long t1=(a-c)*(a-c)+(b-d)*(b-d);
	long long t2=(e-c)*(e-c)+(f-d)*(f-d);
	if(t1!=t2 || ((c-a)==(e-c) && (f-d)==(d-b)))cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}