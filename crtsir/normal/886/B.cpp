#include<iostream>
using namespace std;
int a[200001];
bool pd[200001];
using namespace std;
int main()
{
	int n,js=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(!pd[a[i]])
		{
			pd[a[i]]=true;
			js++;
		}
	}
	for(int i=n-1;js>1;i--)
		if(pd[a[i]]==true)
		{
			js--;
			pd[a[i]]=false;
		}
	for(int i=0;i<200001;i++)
		if(pd[i]==true)
			cout<<i;
}