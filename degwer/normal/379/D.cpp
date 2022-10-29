#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll s1[51],s2[51],s12[51],s21[51],s22[51];
ll count(string s)
{
	ll ret=0;
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			ret++;
		}
	}
	return ret;
}
int main()
{
	s1[1]=1;
	s2[2]=1;
	s1[3]=1;
	s2[3]=1;
	s12[3]=1;
	int k,la,lb;
	ll mok;
	scanf("%d%I64d%d%d",&k,&mok,&la,&lb);
	for(int i=4;i<=50;i++)
	{
		s1[i]=s1[i-1]+s1[i-2];
		s2[i]=s2[i-1]+s2[i-2];
		s12[i]=s12[i-1]+s12[i-2];
		s21[i]=s21[i-1]+s21[i-2]+(i+1)%2;
		s22[i]=s22[i-1]+s22[i-2]+i%2;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int m=0;m<3;m++)
			{
				for(int n=0;n<3;n++)
				{
					string st1,st2;
					st1.resize(la);
					st2.resize(lb);
					fill(st1.begin(),st1.end(),'B');
					fill(st2.begin(),st2.end(),'B');
					st1[0]=i+'A';
					st1[la-1]=j+'A';
					st2[0]=m+'A';
					st2[lb-1]=n+'A';
					//cout<<st1<<" "<<st2<<endl;
					ll nm=mok;
					if(st1[la-1]=='A'&&st2[0]=='C')
					{
						nm-=s12[k];
					}
					if(st2[lb-1]=='A'&&st1[0]=='C')
					{
						nm-=s21[k];
					}
					if(st2[lb-1]=='A'&&st2[0]=='C')
					{
						nm-=s22[k];
					}
					int a1=la,a2=lb;
					if(st1[0]!='A')
					{
						a1--;
					}
					if(st1[la-1]!='C')
					{
						a1--;
					}
					if(st2[0]!='A')
					{
						a2--;
					}
					if(st2[lb-1]!='C')
					{
						a2--;
					}
					a1/=2;
					a2/=2;
					//printf("%d %d\n",a1,a2);
					for(int p=0;p<=a1;p++)
					{
						for(int q=0;q<=a2;q++)
						{
							if(s1[k]*p+s2[k]*q==nm)
							{
								int r1=0,r2=0;
								if(st1[0]!='A')
								{
									r1++;
								}
								if(st2[0]!='A')
								{
									r2++;
								}
								for(int r=0;r<p;r++)
								{
									st1[r1]='A';
									st1[r1+1]='C';
									r1+=2;
								}
								for(int r=0;r<q;r++)
								{
									st2[r2]='A';
									st2[r2+1]='C';
									r2+=2;
								}
								//cout<<st1<<" "<<st2<<" "<<p<<" "<<q<<endl;
								if(s1[k]*count(st1)+s2[k]*count(st2)==nm)
								{
									cout<<st1<<endl<<st2<<endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Happy new year!\n");
}