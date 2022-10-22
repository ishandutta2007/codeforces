/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,x,y,nr[60],nc[60];
vector <pii> v;

int main()
{
	cin>>n;
	rep(i,n*4+1)
	{
		scanf("%d%d",&x,&y);
		v.pb({x,y});
	}
	rep(i,55)
	{
		rep(j,55)
		{
			rep(k,55)
			{
				if(k+j-i>50) break;
				int p=k+j-i,num=0;
				rep(r,n*4+1)
				{
					if(!((v[r].fi==i&&k<=v[r].se&&v[r].se<=p)||(v[r].fi==j&&k<=v[r].se&&v[r].se<=p)||
					(v[r].se==k&&i<=v[r].fi&&v[r].fi<=j)||(v[r].se==p&&i<=v[r].fi&&v[r].fi<=j)))
					{
						num++;
						x=v[r].fi;
						y=v[r].se;
					}
				}
				if(num==1)
				{
					cout<<x<<' '<<y<<endl;
					rt0;
				}
			}
		}
	}
	rt0;
}