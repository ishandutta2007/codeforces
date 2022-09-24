#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using ll=long long;
using namespace std;
const int MOD=998244353,CNT=62,SZ=7;

int n,val[250];
ll cnt[SZ+1][CNT][CNT];
ll cnt2[SZ+1][CNT][CNT][CNT];
string a;
set<string> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while (n--)
	{
		cin>>a;
		v.insert(a);
		reverse(a.begin(),a.end());
		v.insert(a);
	}
	for (int i='a';i<='z';++i) val[i]=i-'a';
	for (int i='A';i<='Z';++i) val[i]=i-'A'+26;
	for (int i='0';i<='9';++i) val[i]=i-'0'+52;
	for (auto a: v)
	{
		++cnt[a.size()-3][val[a[0]]][val[a.back()]];
	}
	for (int s=0;s<=SZ;++s) for (int i=0;i<CNT;++i) for (int j=i;j<CNT;++j) for (int k=j;k<CNT;++k)
	{
		for (int l=0;l<CNT;++l) cnt2[s][i][j][k]+=cnt[s][i][l]*cnt[s][j][l]*cnt[s][k][l];
		cnt2[s][i][j][k]%=MOD;
	}
	int ans=0;
	for (int s=0;s<=SZ;++s) for (int i=0;i<CNT;++i) for (int j=i;j<CNT;++j) for (int k=j;k<CNT;++k) for (int l=k;l<CNT;++l)
	{
		int mul;
		if (i==j && j==k && k==l) mul=1;
		else if ((i==j && j==k) || (j==k && k==l)) mul=4;
		else if (i==j && k==l) mul=6;
		else if (i==j || j==k || k==l) mul=12;
		else mul=24;
		ans=(ans+mul*cnt2[s][i][j][k]%MOD*cnt2[s][i][j][l]%MOD*cnt2[s][i][k][l]%MOD*cnt2[s][j][k][l])%MOD;
	}
	cout<<ans<<endl;
}