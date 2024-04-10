#include <bits/stdc++.h>

using namespace std;

char a,b;
int n;
map<char,int> ma;

int main()
{
	ma['v']=2;
	ma['^']=0;
	ma['>']=1;
	ma['<']=3;
	cin>>a>>b>>n;
	n%=4;
	int raz=ma[b]-ma[a];
	raz+=(raz<0)*4;
	if (n%2==0) cout<<"undefined"<<endl;
	else if (raz==n) cout<<"cw"<<endl;
	else if (raz==n-2+4*(n==1)) cout<<"ccw"<<endl;
	else cout<<"undefined"<<endl;
}