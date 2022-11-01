#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];
map <string , int> mp;

int t,n; 
int p[1000],ms[100][100],p1[100],p2[100];
string a,name[1000];


bool cmp1(int q1,int q2)
{
	if (p[q1]>p[q2])return 1;
	if (p[q1]<p[q2])return 0;
	for (int i=0;i<1000;i++)
	{
		if (ms[q1][i]>ms[q2][i])return 1;
		if (ms[q1][i]<ms[q2][i])return 0;
	}
}

bool cmp2(int q1,int q2)
{
	if (ms[q1][0]>ms[q2][0])return 1;
	if (ms[q1][0]<ms[q2][0])return 0;
	
	if (p[q1]>p[q2])return 1;
	if (p[q1]<p[q2])return 0;
	for (int i=1;i<1000;i++)
	{
		if (ms[q1][i]>ms[q2][i])return 1;
		if (ms[q1][i]<ms[q2][i])return 0;
	}
}

int main()
{
	cin>>t;
	int k=0;
	while (t--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin >> a;
			if (!mp[a])
			{
				k++;
				mp[a]=k;
				name[k]=a;
			}
			int x=mp[a];
			if (i==0)p[x]+=25;
			if (i==1)p[x]+=18;
			if (i==2)p[x]+=15;
			if (i==3)p[x]+=12;
			if (i==4)p[x]+=10;
			if (i==5)p[x]+=8;
			if (i==6)p[x]+=6;
			if (i==7)p[x]+=4;
			if (i==8)p[x]+=2;
			if (i==9)p[x]+=1;
			ms[x][i]++;
		}
	}
	for (int i=0;i<k;i++)p1[i]=i+1;
	for (int i=0;i<k;i++)p2[i]=i+1;
	sort(p1,p1+k,cmp1);// 
	sort(p2,p2+k,cmp2);//
	 
	cout << name[p1[0]] << endl;
	cout << name[p2[0]] << endl;
	return 0;
}