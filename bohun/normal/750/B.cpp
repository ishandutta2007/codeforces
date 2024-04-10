#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
string s;
int a;
int main(){
	cin>>n;
	int x=0,y=0;
	bool ok=1;
	for(int i=1;n>=i;i++)
	{
		cin>>a>>s;
		if(s[0]=='N')
			x+=a;
		if(s[0]=='S')
			x-=a;
		if(s[0]=='E')
			y+=a;
		if(s[0]=='W')
			y-=a;
		if((x==0 or x==-20000) and (s[0]=='E' or s[0]=='W'))
			ok=0;
		ok&=(x<=0 and x>=-20000);
	}
	if(x==0 and ok==1)
		cout<<"YES\n";
	else
		cout<<"NO";
	
    return 0;	
}