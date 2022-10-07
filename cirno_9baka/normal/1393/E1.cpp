#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int M=1000000007;
int n,i,lp[N],j,a[N],la[N],ln,lcp[3][N],t;
char c[N],lc[N];
int dp[N],ldp[N];
bool cmp(int u,int v)
{
	if(lp[min(u,v)]>=abs(v-u))
		return u<v;
	int fl=0;
	if(u>v)
	{
		swap(u,v);
		fl=1;
	}
	return (c[u+lp[u]+1]<c[u+lp[u]])^fl;
}
int main()
{
	scanf("%d",&t);
	for(int m=1;m<=t;++m)
	{
		for(i=1;i<=n;++i)
			c[i]=0;
		scanf("%s",c+1);
		n=strlen(c+1);
		for(i=1;i<=n;)
		{
			for(j=i;c[i]==c[j];++j);
			int p=j;
			for(j=i;c[i]==c[j];++j)
				lp[j]=p-j-1;
			i=j;
		}
		for(i=1;i<=n;++i)
			a[i]=i;
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;++i)
			if(a[i]+lp[a[i]]+1<=n&&c[a[i]+lp[a[i]]+1]>c[a[i]+lp[a[i]]])
			{
				for(j=n+1;j>i;--j)
					a[j]=a[j-1];
				break;
			}
		a[i]=0;
		//for(i=1;i<=n+1;++i)
		//	cout<<a[i]<<' ';
		//cout<<endl;
		if(m==1)
		{
			for(i=1;i<=n+1;++i)
				dp[i]=i;
		}
		else
		{
			for(int f=-1;f<=1;++f)
				for(i=1;i<=ln;++i)
				{
					lcp[f+1][i]=max(lcp[f+1][i-1]-1,0);
					while(i+lcp[f+1][i]<=ln&&i+f+lcp[f+1][i]<=n&&lc[i+lcp[f+1][i]]==c[i+f+lcp[f+1][i]])
						++lcp[f+1][i];
				}
			int l=1;
			for(i=1;i<=n+1;++i)
			{
				while(l<=ln+1)
				{
					//cout<<'#'<<la[l]<<' '<<a[i]<<endl;
					if(la[l]!=0&&a[i]!=0)
					{
						if(la[l]<a[i])
						{
							if(lcp[1][1]<la[l]-1)
							{
								if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
									break;
							}
							else
								if(lcp[0][la[l]+1]<a[i]-la[l])
								{
									if(lc[la[l]+1+lcp[0][la[l]+1]]>c[la[l]+lcp[0][la[l]+1]])
										break;
								}
								else
									if(lc[a[i]+1+lcp[1][a[i]+1]]>c[a[i]+1+lcp[1][a[i]+1]])
										break;
						}
						if(la[l]==a[i])
						{
							if(lcp[1][1]<la[l]-1)
							{
								if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
									break;
							}
							else
							{
								if(lc[a[i]+1+lcp[1][a[i]+1]]>c[a[i]+1+lcp[1][a[i]+1]])
									break;
							}
						}
						if(la[l]>a[i])
						{
							if(lcp[1][1]<a[i]-1)
							{
								if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
									break;
							}
							else
								if(lcp[2][a[i]]<la[l]-a[i])
								{
									if(lc[a[i]+lcp[2][a[i]]]>c[a[i]+1+lcp[2][a[i]]])
										break;
								}
								else
									if(lc[la[l]+1+lcp[1][la[l]+1]]>c[la[l]+1+lcp[1][la[l]+1]])
										break;
						}
					}
					if(la[l]!=0&&a[i]==0)
					{
						if(lcp[1][1]<la[l]-1)
						{
							if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
								break;
						}
						else
							if(lc[la[l]+1+lcp[0][la[l]+1]]>c[la[l]+lcp[0][la[l]+1]])
								break;
					}
					if(la[l]==0&&a[i]!=0)
					{
						if(lcp[1][1]<a[i]-1)
						{
							if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
								break;
						}
						else
							if(lc[a[i]+lcp[2][a[i]]]>c[a[i]+1+lcp[2][a[i]]])
								break;
					}
					if(la[l]==0&&a[i]==0)
						if(lc[1+lcp[1][1]]>c[1+lcp[1][1]])
							break;
					++l;
				}
				dp[i]=ldp[l-1];
				//cout<<l<<' ';
			}
			//cout<<endl;
			for(i=1;i<=n+1;++i)
				dp[i]=(dp[i-1]+dp[i])%M;
		}
		for(i=1;i<=ln;++i)
			lc[i]=0;
		for(i=1;i<=n;++i)
			lc[i]=c[i];
		for(i=1;i<=n+1;++i)
		{
			la[i]=a[i];
			ldp[i]=dp[i];
		}
		ln=n;
	}
	cout<<dp[n+1]<<endl;
}