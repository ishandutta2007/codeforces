#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool pri[3001];
vector<int> prilis;
void matpri(int wil,int n)
{
	if(wil==n+1)
		return;
	if(!pri[wil])
	{
		matpri(wil+1,n);
		return;
	}
	for(int i=wil*2;i<=n;i+=wil)
		pri[i]=false;
	prilis.push_back(wil);
	matpri(wil+1,n);
}
bool almp(int x)
{
	set<int> pridiv;
	int no=0,cnt=0;
	while(!pri[x])
		if(x%prilis[cnt])
			cnt++;
		else
		{
			pridiv.insert(prilis[cnt]);
			x/=prilis[cnt];
		}
	pridiv.insert(x);
	return pridiv.size()==2;
}
int main()
{
	int n,i,no=0;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(i=2;i<=n;i++)
		pri[i]=true;
	matpri(2,n);
	for(i=2;i<=n;i++)
		if(almp(i))
			no++;
	cout<<no;
	return 0;
}
/*1
10
*/
/*2
21
*/