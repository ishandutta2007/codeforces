#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	lli lt,rt,n1,n2,up;
	int f=0;
	bool k=true;
	for(int i=0;i<n&&k;i++)
	{
		for(int j=0;j<m&&k;j++)
		{
			char c;
			cin>>c;
			if(c=='B'&&f==0)
			{
				f=1;
				lt=j;
				up=i;
			}
			if(f==1&&j==m-1&&c=='B')
			{
				k=false;
				rt=m-1;
			}
			else if(f==1&&c=='W')
			{
				k=false;
				rt=j-1;
			}
		}
		
	}
	n2=(lt+rt)/2;
	n1=(up+(rt-lt)/2);
	cout<<n1+1<<" "<<n2+1;
	return 0;
}