#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=1010;

int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	return (y,x%y);
}

int n,m;
string s[N],t[N];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>t[i];
	int q; cin>>q;
	while(q--)
	{
		int x;
		cin>>x; x--;
		cout<<s[x%n]<<t[x%m]<<endl;
	}
	return 0;
}