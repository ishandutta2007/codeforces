
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1100000;
char s[N];
int n;
int main()
{
	cin>>n;
	scanf("%s",s+1);
	int left=0,right=0;
	for(int i=1;i<=n;i++)
		if (s[i]=='(')left++; else right++;
	if (left!=right){ puts("-1"); return 0; }
	int cnt=0,ans=0,pre;
	for(int i=1;i<=n;i++)
		if (s[i]=='(')
		{
			cnt++;
			if (cnt==0)ans+=(i-pre+1);  
		}
		else
		{
			cnt--;
			if (cnt==-1)pre=i;
		}
	cout<<ans<<endl;
	return 0;
}