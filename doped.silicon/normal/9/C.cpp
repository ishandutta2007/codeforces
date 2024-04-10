#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
lli convert(lli n)
{
	string s="";
	while(n!=0)
	{
		lli k=n%2;
		if(k==0)
		s="0"+s;
		else
		s="1"+s;
		n/=2;
	}
	n=stoi(s);
	return n;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli ar[1000000]={0};
	lli n,k=1,k1;
	cin>>n;
	for(int i=2;i<n;i++)
	{
		k1=convert(i);
		if(k1>n)
		break;
		else
		k++;
	}
	cout<<k;
	return 0;
}