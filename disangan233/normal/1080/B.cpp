
 #include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if((a&1)==(b&1))
		{
		    if(a&1) cout<<1*(b-a)/2-b<<endl;
			else cout<<-1*(b-a)/2+b<<endl;
		}
		else 
		{
			if(a&1) cout<<1*(b-a+1)/2<<endl;
			else cout<<-1*(b-a+1)/2<<endl;
		}
	}
}