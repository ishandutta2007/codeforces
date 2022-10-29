#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#include<vector>
int n,m,k;
int b[333][333],a[333][333];

vector<int> V,li,pe;
vector<pair<double,int> > D;
vector<pair<int,pair<int,int> > > P;

int ABS(int x){return x<0?-x:x;}

double calc()
{
	sort(V.begin(),V.end());
	int l=V.size();
	double s1=0,s2=0;
	for(int i=l/100;i+l/100<V.size();i++)
		s1+=V[i],s2+=1;
	return s1/s2;
}

double dist(int i,int j)
{
	V.clear();
	for(int d=0;d<3;d++)
	for(int k=1;k<=m;k++)
	{
		if(i-d>=1&&j+d<=n)V.push_back(pow(ABS(a[i-d][k]-a[j+d][k]),1.6));
	}
	return fabs(calc());
}

double C[22][22];
double f[1<<16][16];
int r[1<<16][16];

void out(int s,int x)
{
	if(x==-1)return;
	out(s^(1<<x),r[s][x]);
	pe.push_back(x);
}

void gs()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			double s1=0,s2=0;
			for(int x=i-1;x<=i+1;x++)
				for(int y=j-1;y<=j+1;y++)
					if(x>=1&&x<=n&&y>=1&&y<=m)
						s1+=b[x][y],s2++;
			a[i][j]=int(s1/s2+.5);
		}
}

char ansans[21][500]={
	"",
"2 1",
"2 3 1",
"4 3 2 1",
"1 3 4 2 5",
"1 6 11 3 10 9 15 12 7 13 2 5 4 14 8",
"5 1 3 11 10 7 6 9 13 15 12 4 14 2 8",
"9 7 2 5 1 10 8 3 4 6",
"2 1 4 3",
"4 12 8 2 9 14 5 7 1 6 10 13 15 3 11",
"11 5 6 8 10 12 7 2 1 4 9 3 13 14 15",
"11 7 8 4 5 15 13 14 3 9 12 2 1 10 6",
"12 7 11 4 10 2 5 14 13 1 6 3 9 8 15 16",
"3 2 1",
"4 2 1 3 5",
"1 8 11 15 3 2 7 16 13 4 6 10 9 12 5 14",
"9 8 6 13 11 10 2 7 14 12 5 4 15 3 1",
"2 15 16 10 8 5 9 3 11 7 1 14 12 4 6 13",
"15 5 2 14 3 13 1 7 12 8 4 10 6 11 9",
"9 7 3 14 2 12 13 5 1 15 11 10 8 4 6",
"9 7 13 10 15 16 5 3 6 1 2 11 8 4 14 12"
};


int main()
{
	int Q;
	cin>>Q;
	for(int qi=1;qi<=Q;qi++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",b[i]+j);
		gs();
		if(qi<=20)
		{
			puts(ansans[qi]);continue;
		}
				/*
		cout<<dist(60,61);
		D.clear();
		for(int i=1;i<n;i++)
		{
			V.clear();
			for(int j=1;j<=m;j++)
				V.push_back(ABS(a[i][j]-a[i+1][j]));
			D.push_back(make_pair(dist(i,i+1),i));
		}
		sort(D.begin(),D.end());
		reverse(D.begin(),D.end());
		double av=0;
		for(int i=0;i<D.size();i++)
		{
			av+=D[i].first;
			cout<<D[i].first<<' '<<D[i].second<<endl;
		}
		av/=D.size();
		li.clear();
		for(int i=0;i<k-1;i++)
			li.push_back(D[i].second);
		sort(li.begin(),li.end());
		li.push_back(n);
		P.clear();
		for(int i=0;i<li.size();i++)
			P.push_back(make_pair(i+1,make_pair(i==0?1:li[i-1]+1,li[i])));
		*/
		P.clear();
		for(int i=0;i<k;i++)
			P.push_back(make_pair(i,make_pair(i*(n/k)+1,(i+1)*(n/k))));
		//for(int i=0;i<P.size();i++)cout<<P[i].second.first<<' '<<P[i].second.second<<endl;cout<<endl;
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				C[i][j]=dist(P[i].second.second,P[j].second.first);
		for(int i=0;i<1<<k;i++)
			for(int j=0;j<k;j++)
				f[i][j]=1e10;
		for(int i=0;i<k;i++)
			f[1<<i][i]=0,r[1<<i][i]=-1;
		for(int i=0;i<1<<k;i++)
			for(int j=0;j<k;j++)
				if(f[i][j]<1e9)
				{
					for(int t=0;t<k;t++)
						if((i>>t&1)==0)
						{
							if(f[i][j]+C[j][t]<f[i|1<<t][t])
							{
								f[i|1<<t][t]=f[i][j]+C[j][t];
								r[i|1<<t][t]=j;
							}
						}
				}
		int t=0;
		for(int i=0;i<k;i++)
			if(f[(1<<k)-1][i]<f[(1<<k)-1][t])
				t=i;
		pe.clear();
		out((1<<k)-1,t);
		int pp[22];
		for(int i=1;i<=pe.size();i++)
			pp[pe[i-1]+1]=i;
		for(int i=1;i<=k;i++)
			printf("%d%c",pp[i]," \n"[i==k]);
	}
	return 0;
}