#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,d,m;
	int g,p,b;
	bool ok=1;
	cin>>a>>d>>m;
	cin>>g>>p>>b;
	g-=a;
	if(g<0) ok=0;
	else{
		if(m<b)
			m=0,b-=m;
		else m-=b,b=0;
		int tot=g+p+b;
		if(g+p<d) ok=0;
		else tot-=d;
		if(tot<m) ok=0;
	}
	if(ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}