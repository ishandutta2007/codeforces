#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

int a[3];
bool f2[300][300],d2[300][300];

bool calc1(int a)
{
	return (a>0);
}

bool calc2(int a1,int a2)
{
	bool &f=f2[a1][a2];
	bool &d=d2[a1][a2];
	if (f)return d;
	f=true;
	d=false;

	for (int i=1; i<=a1; i++)
		d|=(!calc2(a1-i,a2));
	for (int i=1; i<=a2; i++)
		d|=(!calc2(a1,a2-i));
	int mn=min(a1,a2);
	for (int i=1; i<=mn; i++)
		d|=(!calc2(a1-i,a2-i));
	return d;
}

bool ans[300][300][300],
d12[300][300],
da[300][300];

bool calc3(int a1,int a2,int a3)
{
	for (int i=0; i<300; i++)
		for (int j=i; j<300; j++)
			for (int k=j; k<300; k++)
			{
				bool& a=ans[i][j][k];
				a=a|d12[i][j]|d12[i][k]|d12[j][k]|da[j-i][k-i];
			
				da[j-i][k-i]|=(!a);
				d12[i][j]|=(!a);
				d12[i][k]|=(!a);
				d12[j][k]|=(!a);
			}
	if (a2<a1)swap(a1,a2);
	if (a3<a1)swap(a1,a3);
	if (a3<a2)swap(a3,a2);
	return ans[a1][a2][a3];
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	for (int i=0; i<n; i++)cin >> a[i];
	bool ans;
	if (n==1)ans=calc1(a[0]);
	if (n==2)ans=calc2(a[0],a[1]);
	if (n==3)ans=calc3(a[0],a[1],a[2]);
		
	if (ans)
		cout << "BitLGM" << endl;
	else
		cout << "BitAryo" << endl;
	return 0;
}