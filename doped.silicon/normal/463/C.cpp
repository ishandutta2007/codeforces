#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
lli ar[2][2];
lli s[2]={-1,-1};
void update(lli i,lli j, lli val)
{
      int k=(i+j)%2;
      if(val>s[k])
      {
      	s[k]=val;
      	ar[k][0]=i+1;
      	ar[k][1]=j+1;
      }
}
int main() {
	#ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
        freopen("date.out","w",stdout);
    #endif
    cin.sync_with_stdio(false);
	lli n;
	cin>>n;
	lli d1[2*(n+14)]={0},d2[2*(n+14)]={0};
	lli a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			d1[i+j]+=a[i][j];
			d2[n-i+j]+=a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			update(i,j,d1[i+j]+d2[n-i+j]-a[i][j]);
		}
	}
	cout<<s[0]+s[1]<<endl;
	cout<<ar[0][0]<<" "<<ar[0][1]<<" "<<ar[1][0]<<" "<<ar[1][1];
	
	
	return 0;
}