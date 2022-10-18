#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=355;
deque<int>a[N];
int n,m,s,q,z,L,R,k,l,r,x,ans,c[M][N];
void deal(int &x){x=(x+ans-1)%n+1;} 
int main()
{
	scanf("%d",&n);
	s=int(sqrt(n)),m=n/s+1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[i/s].push_back(x);
		c[i/s][x]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&z,&L,&R);
		deal(L),deal(R);
		if(L>R) swap(L,R);
		L--,l=L/s,r=R/s;
		if(z==2)
		{
			scanf("%d",&k);
			deal(k);
			ans=0;
			if(l==r)
				for(int i=L%s;i<R%s;i++)
					ans+=a[l][i]==k;
			else
			{
				for(int i=l+1;i<r;i++)
					ans+=c[i][k];
				for(int i=L%s;i<a[l].size();i++)
					ans+=a[l][i]==k;
				for(int i=0;i<R%s;i++)
					ans+=a[r][i]==k;
			}
			printf("%d\n",ans);
		}
		else
		{
			if(l==r)
			{
				R=R%s-1,x=a[r][R];
				a[r].erase(a[r].begin()+R);
				a[l].insert(a[l].begin()+L%s,x);
			}
			else
			{
				for(int i=l;i<r;)
				{
					x=a[i].back(),a[i].pop_back(),c[i][x]--,i++;
					a[i].push_front(x),c[i][x]++;	
				} 
				R%=s,x=a[r][R];
				a[r].erase(a[r].begin()+R),c[r][x]--;
				a[l].insert(a[l].begin()+L%s,x),c[l][x]++;
			}
		}
	}
	return 0;
}