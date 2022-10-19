#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,r,b,cnt;
bool flg;
bool isgood[1005];
vector<int> v;
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		if(b) v.push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		if(!isgood[i])
		{
			flg=0;
			for(int j=v.size()-1;j>=0;j--)
			{
				if(abs(v[j]-i)<r)
				{
					flg=1;
					++cnt;
					for(int k=v[j]-r+1;k<v[j]+r;k++)
					{
						if(0<=k&&k<n) isgood[k]=1;
					}
					break;
				}
			}
			if(!flg)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}