#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int main()
{
	string s;
	cin>>s;
	int cnt4=0,cnt7=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='4') cnt4++;
		if(s[i]=='7') cnt7++;
	}
	if(cnt4==0&&cnt7==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(cnt4>=cnt7)
	{
		cout<<4<<endl;
		return 0;
	}
	cout<<7<<endl;
	return 0;
}