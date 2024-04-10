#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define per(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define prt(n) cout<<(n)<<endl;
using namespace std;
int n,res,plc;
long long a[200005];
int main()
{
	cin>>n;
	rep(i,n) cin>>a[i];
	while(plc<n)
	{
		res++;
		int lst=0,tis=0,val=0;
		while(plc<n&&a[plc]==-1)
		{
			lst++;
			plc++;
		}
		if(plc==n)
		break;
		val=a[plc];
		plc++;
		while(plc<n&&a[plc]==-1)
		{
			tis++;
			plc++;
		}
		if(plc==n)
		break;
		int valu=a[plc];
		if((valu-val)%(tis+1)!=0) // 
		continue;
		long long dif=(valu-val)/(tis+1);
		if(val-lst*dif<=0) // 
		continue;
		plc++;
		while(plc<n)
		{
			if(a[plc]==-1)
			{
				if(a[plc-1]+dif<=0) //
				break;
				a[plc]=a[plc-1]+dif;
				plc++; 
			}
			else if(a[plc]!=a[plc-1]+dif) //
			break;
			else
			plc++; 
		}
	}
	prt(res);
	return 0;
}