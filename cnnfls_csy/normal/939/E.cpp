#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
vector<double> num,cnt;
int n,m,i,j,op,x,qx[600005],ql,qr;
double l,r,mid,ans,lst;
double get(int i)
{
	return num[num.size()-1]-(num[num.size()-1]+cnt[i])/(i+2);
}
int main()
{
	scanf("%d",&n);
	lst=0;
	while (n--)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d",&x);
			num.push_back(x);
			if (!cnt.empty()) cnt.push_back(cnt.back()+x); else cnt.push_back(x);
			if (num.size()>1)
			{
				while (ql<qr&&get(qx[qr-1])<=get(num.size()-2)) qr--;
				qx[qr++]=num.size()-2;
			}
			for (i=ql+1;i<=ql+450&&i<qr;i++)
			{
				if (get(qx[i])>get(qx[ql])) ql=i;
			}
		}
		if (op==2)
		{
			printf("%.10f\n",get(qx[ql]));
		}
	}
	return 0;
}