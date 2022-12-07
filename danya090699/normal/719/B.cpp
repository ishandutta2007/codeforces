#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n;
	string s;
	cin>>n>>s;
	int bq=0, rq=0, bch=0, rch=0, ans;
	for(int a=0; a<n; a++)
	{
		if(s[a]=='b')
		{
			if(a%2==0) bch++;
			bq++;
		}
		else
		{
			if(a%2==0) rch++;
			rq++;
		}
	}
	int b, r=n/2, pai;
	b=n-r;
	if(b<bq) ans=bq-bch;
	else ans=rch;
	b=n/2;
	r=n-b;
	if(b<bq) ans=min(ans, bch);
	else ans=min(ans, rq-rch);
	cout<<ans;
}