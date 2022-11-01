#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int fa[123],a[123];
int getfather(int x)
{
	return fa[x] == x? x:fa[x] = getfather(fa[x]);
}
void union_set(int x,int y)
{
	int x_fa = getfather(x);
	fa[x_fa] = getfather(y);
}
//cellcell
//cellpermutationYESNO
//DSU 
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		//|i-j|=d_i, 
		if(i-x>0)
		{
			union_set(i,i-x);
		}
		if(i+x<=n)
		{
			union_set(i,i+x);
		}
	}
	int f = 1;
	for(int i=1;i<=n;i++)
	{
		if(f==1)
		{
			f = getfather(i) == getfather(a[i])? 1 : 0;
		}
		else break;
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
 }