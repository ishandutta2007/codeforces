#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,k;
	cin>>n>>k;
	string s,s1="";
	cin>>s;
	int p=0;
	bool m=true;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]!=s[i+1])
		m=false;
	}
	if(m)
	{
		cout<<s;
		for(int i=0;i<k-1;i++)
		cout<<s[0];
	}
	else
	{
		
	for(int i=0;i<n-1;i++)
	{
		bool x=true;
		int y=0;
		for(int j=n-1-i;j<n&&x;j++)
		{
			//cout<<"Ssa"<<j;
			//bool kf=s[y]!=s[j];
			//cout<<kf<<endl;
			if(s[y]!=s[j])
			x=false;
			y++;
		}
		//cout<<i<<x;
		if(x)
		p=i+1;
		//cout<<"p=="<<p;
	}
	 
		s1+=s.substr(p,n-p);
		//cout<<s1+'\n';
	cout<<s;
	for(int i=0;i<k-1;i++)
		cout<<s1;
	}
	return 0;
}