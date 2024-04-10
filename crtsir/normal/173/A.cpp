#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	else return gcd(b,a%b);
}
bool iFlose(char c1,char c2)
{
	if((c1=='R'&&c2=='P')||(c1=='P'&&c2=='S')||(c1=='S'&&c2=='R'))return true;
	return false; 
}
int main()
{
	string s1,s2;
	int n,len1,len2,ans1=0,ans2=0;
	cin>>n>>s1>>s2;
	len1=s1.size(),len2=s2.size();
	int tot=len1/gcd(len1,len2)*len2;
	for(int i=0;i<tot;i++)
	{
		int x=i%s1.size(),y=i%s2.size();
		if(iFlose(s1[x],s2[y]))ans1++;
		if(iFlose(s2[y],s1[x]))ans2++;
	}
	ans1=ans1*(n/tot);
	ans2=ans2*(n/tot);
	for(int i=0;i<n%tot;i++)
	{
		int x=i%s1.size(),y=i%s2.size();
		if(iFlose(s1[x],s2[y]))ans1++;
		if(iFlose(s2[y],s1[x]))ans2++;
	}
	cout<<ans1<<' '<<ans2;
}