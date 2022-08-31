#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map> 
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,k,l,x,y,num[1005],num2[1005];
unsigned long long h1[1005],h2[1005],h3[1005],h4[1005],h5[1005],h6[1005],h7[1005],h8[1005],e=1e9+7,e2=1e9+9,inv,p[1005],pi[1005];
unsigned long long gth1(int l,int r){if (l>r) return 0;return ((h1[r]-h1[l-1]*p[r-l+1])*p[n-r]);}
unsigned long long gth3(int l,int r){if (l>r) return 0;return ((h3[r]-h3[l-1]*p[r-l+1])*p[n-r]);}
unsigned long long gth2(int l,int r){if (l>r) return 0;return ((h2[l]-h2[r+1]*p[r-l+1])*p[n-r]);}
unsigned long long gth4(int l,int r){if (l>r) return 0;return ((h4[l]-h4[r+1]*p[r-l+1])*p[n-r]);}
unsigned long long gth5(int l,int r){if (l>r) return 0;return ((h5[r]-h5[l-1]*pi[r-l+1])*pi[n-r]);}
unsigned long long gth7(int l,int r){if (l>r) return 0;return ((h7[r]-h7[l-1]*pi[r-l+1])*pi[n-r]);}
unsigned long long gth6(int l,int r){if (l>r) return 0;return ((h6[l]-h6[r+1]*pi[r-l+1])*pi[n-r]);}
unsigned long long gth8(int l,int r){if (l>r) return 0;return ((h8[l]-h8[r+1]*pi[r-l+1])*pi[n-r]);}
map<pair<unsigned long long,unsigned long long>,pair<int,int> > can;
vector<int> v1,v2;
int main()
{
	scanf("%d",&n);
	fz1(i,n) scanf("%d",&num[i]);
	p[0]=pi[0]=1;
	fz1(i,n)
	{
		p[i]=p[i-1]*e;
		pi[i]=pi[i-1]*e2;
		h1[i]=(h1[i-1]*e+i);
		h5[i]=(h5[i-1]*e2+i);
	}
	fd1(i,n)
	{
		h2[i]=(h2[i+1]*e+i);
		h6[i]=(h6[i+1]*e2+i);
	}
	can[make_pair(gth1(1,n),(gth5(1,n)))]=make_pair(1,1);
	fz1(i,n)
	{
		fz(j,i+1,n)
		{
			//cerr<<gth1(i,j)<<' ';
			//cerr<<gth2(i,j)<<' ';
			can[make_pair((gth1(1,i-1)+gth2(i,j)+gth1(j+1,n)),(gth5(1,i-1)+gth6(i,j)+gth5(j+1,n)))]=make_pair(i,j);
		}
		//cerr<<endl;
	}
//	ff(can,it)
//	{
//		cerr<<it->first.first<<' '<<it->first.second<<' '<<it->second.first<<' '<<it->second.second<<endl;
//	}
	v1.push_back(1);
	if (n>=2) v1.push_back(2);
	v1.push_back(n);
	if (n>=2) v1.push_back(n-1);
	for (i=2;i<=n;i++)
	{
		if (abs(num[i]-num[i-1])!=1)
		{
			v1.push_back(i-1);
			v1.push_back(i);
			if (i-2>=1) v1.push_back(i-2);
			if (i+1<=n) v1.push_back(i+1);
		}
	}
	sort(v1.begin(),v1.end());
	v1.resize(unique(v1.begin(),v1.end())-v1.begin());
	for (i=0;i<v1.size();i++)
	{
		for (j=i;j<v1.size();j++)
		{
			x=v1[i];y=v1[j];
			memcpy(num2,num,sizeof(num2));
			reverse(num2+x,num2+y+1);
			fz1(k,n)
			{
				h3[k]=(h3[k-1]*e+num2[k]);
				h7[k]=(h7[k-1]*e2+num2[k]);
			}
			fd1(k,n)
			{
				h4[k]=(h4[k+1]*e+num2[k]);
				h8[k]=(h8[k+1]*e2+num2[k]);
			}
			v2.clear();
			v2.push_back(1);
			if (n>=2) v2.push_back(2);
			v2.push_back(n);
			if (n>=2) v2.push_back(n-1);
			for (k=2;k<=n;k++)
			{
				if (abs(num2[k]-num2[k-1])!=1)
				{
					v2.push_back(k-1);
					v2.push_back(k);
					if (k-2>=1) v2.push_back(k-2);
					if (k+1<=n) v2.push_back(k+1);
				}
			}
			sort(v2.begin(),v2.end());
			v2.resize(unique(v2.begin(),v2.end())-v2.begin());
			for (k=0;k<v2.size();k++)
			{
				for (l=k;l<v2.size();l++)
				{
					int a=v2[k],b=v2[l];
					pair<unsigned long long,unsigned long long> hsh=make_pair((gth3(1,a-1)+gth4(a,b)+gth3(b+1,n)),(gth7(1,a-1)+gth8(a,b)+gth7(b+1,n)));
					if (can.count(hsh))
					{
						int cnt=0;
						if (can[hsh].first<can[hsh].second) cnt++;
						if (a<b) cnt++;
						if (x<y) cnt++;
						cout<<cnt<<endl;
						if (can[hsh].first<can[hsh].second) cout<<can[hsh].first<<' '<<can[hsh].second<<endl;
						if (a<b) cout<<a<<' '<<b<<endl;
						if (x<y) cout<<x<<' '<<y<<endl;
						return 0;
					}
				}
			}
		}
	}
	return -1;
}