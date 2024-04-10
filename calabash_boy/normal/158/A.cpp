#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int score[55];
	for (int i=1;i<=n;i++)
	cin>>score[i];
	sort(score,score+n,cmp);
	if (score[k]==0)
	{
	int ans=0;
	for (int i=1;i<=k;i++)
	if (score[i]>0) ans++;
	cout<<ans;
	return 0; 
	}
	int plus=0,temp=k+1;
	while(score[temp]==score[k]&&temp<=n)
	{
		plus++;
		temp++;
	}
	cout<<k+plus;
	return 0;
}