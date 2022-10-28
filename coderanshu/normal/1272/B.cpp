#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long int t,l,r,u,d,m1,sum,m2,i;
	string s;
	cin>>t;
	while(t--)
	{
		l=r=u=d=0;
		cin>>s;
		for(i=0;s[i];i++)
		{
			if(s[i]=='L')l++;
			if(s[i]=='R')r++;
			if(s[i]=='U')u++;
			if(s[i]=='D')d++;
		}
		sum=abs(l-r)+abs(u-d);
		m1=min(l,r);m2=min(u,d);
		if(m1==0 && m2!=0)
			m2=1;
		if(m1!=0 && m2==0)
			m1=1; 
		cout<<s.length()+2*m1-l-r-d-u+2*m2<<"\n";

		for(i=0;i<m1;i++)cout<<"L";
        for(i=0;i<m2;i++)cout<<"U";
		for(i=0;i<m1;i++)cout<<"R";
		for(i=0;i<m2;i++)cout<<"D";
			
		cout<<"\n";


	}
	return 0;
}