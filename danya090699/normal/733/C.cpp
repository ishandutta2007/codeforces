#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, k;
	cin>>n;
	int be[n], yk=0, sz=0;
	for(int a=0; a<n; a++) cin>>be[a];
	cin>>k;
	int ans[n-k][2];
	bool pos=1;
	for(int a=0; a<k; a++)
	{
		int cu, st=yk, ma=0, mi=1e9;
		cin>>cu;
		while(yk<n)
		{
			if(cu>0)
			{
				cu-=be[yk], ma=max(ma, be[yk]), mi=min(mi, be[yk]);
				yk++;
			}
			else break;
		}
		if((cu==0)and(ma!=mi))
		{
			int fi=-1, nap, nu;
			for(int b=st; b<yk; b++)
			{
				if(b-1>=st) if(be[b]==ma and be[b-1]<ma)
				{
					fi=b, nap=0;
				}
				if(b+1<yk) if(be[b]==ma and be[b+1]<ma)
				{
					fi=b, nap=1;
				}
			}
			nu=a+fi-st+1;
			if(nap==0)
			{
				for(int b=fi-1; b>=st; b--)
				{
					ans[sz][0]=nu, ans[sz][1]=0, nu--, sz++;
				}
				for(int b=fi+1; b<yk; b++)
				{
					ans[sz][0]=nu, ans[sz][1]=1, sz++;
				}
			}
			else
			{
				for(int b=fi+1; b<yk; b++)
				{
					ans[sz][0]=nu, ans[sz][1]=1, sz++;
				}
				for(int b=fi-1; b>=st; b--)
				{
					ans[sz][0]=nu, ans[sz][1]=0, nu--, sz++;
				}
			}
		}
		else
		{
			if(!(cu==0 and yk-st==1))
			{
				pos=0;
				break;
			}
		}
	}
	if(yk!=n) pos=0;
	if(pos)
	{
		cout<<"YES\n";
		for(int a=0; a<(n-k); a++)
		{
			cout<<ans[a][0]<<" ";
			if(ans[a][1]==0) cout<<"L";
			else cout<<"R";
			cout<<"\n";
		}
	}
	else cout<<"NO";
}