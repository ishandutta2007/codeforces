#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
char s[110000];
int a[30];
int n,k;
int main()
{
	cin>>n>>k;
	scanf("%s",s+1);
	rep(i,n)a[s[i]-'A'+1]++;
	int ans=2147483647;
	rep(i,k)ans=min(ans,a[i]);
	cout<<ans*k<<endl;
	return 0;
}