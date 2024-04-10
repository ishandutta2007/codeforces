#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) int x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	fast
	string s;
	cin>>s;
	int ans[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			ans[i][j]=0;
	for(int x=0;x<=9;x++)
	{
		for(int y=0;y<=9;y++)
		{
			int ds[10][10];
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				{
					int f=0;
					for(int cnt1=0;cnt1<=9;cnt1++)
					{
						for(int cnt2=0;cnt2<=9;cnt2++)
						{
							if(cnt1==0 && cnt2==0)continue;
							if((i+cnt1*x+cnt2*y)%10==j&&f==0)
							{
								f=1;
								ds[i][j]=cnt1+cnt2;
							}
							else if((i+cnt1*x+cnt2*y)%10==j)
							{
								ds[i][j]=min(ds[i][j],cnt1+cnt2);
							}
						}
					}
					if(f==0) ds[i][j]=-1;
				}
			}
			/*if(x==1&&y==1)
			{
				cout<<ds[0][8]<<" "<<ds[8][4]<<" "<<ds[4][0]<<endl;
			}*/
/*			cout<<ds[0][8]<<" "<<ds[8][4]<<" "<<ds[4][0]<<endl;
*/			for(int i=0;i<s.length()-1;i++)
			{
				if(ds[s[i]-48][s[i+1]-48]==-1)
				{
					ans[x][y]=-1;
					break;
				}
				else
				{
					ans[x][y]+=(ds[s[i]-48][s[i+1]-48]-1);
				}
			}
			cout<<ans[x][y]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
/*-1 17 7 7 7 -1 2 17 2 7 
17 17 7 5 5 5 2 7 2 7 
7 7 7 4 3 7 1 7 2 5 
7 5 4 7 3 3 2 5 2 3 
7 5 3 3 7 7 1 7 2 7 
-1 5 7 3 7 -1 2 9 2 7 
2 2 1 2 1 2 2 2 0 1 
17 7 7 5 7 9 2 17 2 3 
2 2 2 2 2 2 0 2 2 2 
7 7 5 3 7 7 1 3 2 7 

-1 17 7 7 7 -1 2 17 2 7 
17 7 7 7 -1 2 17 2 7 -1 
7 7 7 -1 2 17 2 7 -1 17 
7 7 -1 2 17 2 7 -1 17 7 
7 -1 2 17 2 7 -1 17 7 7 
-1 2 17 2 7 -1 17 7 7 7 
2 17 2 7 -1 17 7 7 7 -1 
17 2 7 -1 17 7 7 7 -1 2 
2 7 -1 17 7 7 7 -1 2 17 
7 -1 17 7 7 7 -1 2 17 2*/