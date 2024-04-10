#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ins{
	ll ti,cnt;
};
int main()
{
	ll mx=(1LL<<32)-1;
	int n;
	cin>>n;
	ll x=0;
	stack<ins> ff;
	ff.push(ins {1,0});
	bool ok=1;
	while(n--)
	{
		string tmp;
		cin>>tmp;
		if(tmp[0]=='a')
			ff.top().cnt+=ff.top().ti;
		else if(tmp[0]=='f')
		{
			int ti;
			cin>>ti;
			ff.push(ins{ti,0});
		}
		else {
			ins cur=ff.top();
			ff.pop();
			ff.top().cnt+=ff.top().ti*cur.cnt;
		}
		if(ff.top().cnt>mx) ok=0;
	}
	if(ok)
		cout<<ff.top().cnt<<endl;
	else cout<<"OVERFLOW!!!"<<endl;
}