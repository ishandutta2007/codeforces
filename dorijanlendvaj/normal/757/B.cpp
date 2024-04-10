#include <bits/stdc++.h>

using namespace std;

int n;
int s[100001];
int ko[100001];
int pri[100001];
int kol[100001];
bool npr[100001];
int e,ma,q;

void eras()
{
	for (int i=2;i<100000;++i)
	{
		if (npr[i]) continue;
		for (int j=i*2;j<=100000;j+=i)
		{
			npr[j]=true;
		}
	}
}

int main()
{
	eras();
	cin>>n;
	for (int i=2;i<=100000;++i)
	{
		if (!npr[i])
		{
			pri[q]=i;
			++q;
			++e;
		}
		kol[i]=q;
	}
	npr[1]=false;
	for (int i=0;i<n;++i)
	{
		cin>>s[i];
		int r=s[i];
		if (!npr[s[i]]) ++ko[s[i]];
		else
		{
			for (int j=0;j<kol[r];++j)
			{
				if (r%pri[j]==0)
				{
					r/=pri[j];
					++ko[pri[j]];
				}
			}
		}
	}
	for (int i=1;i<=100000;++i)
	{
		if (i==1) ko[i]=1;
		ma=max(ko[i],ma);
	}
	cout<<ma<<endl;
}