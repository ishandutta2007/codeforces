#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double PI = acos(-1.0);
int main()
{
	//printf("%d ",1<<24+rand()%2333/2332);
	int n;
	cin>>n;
	int x,y;
	vector< pair<long double,int> >ang;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		ang.push_back( make_pair(atan2( x , y ),i ) );
		
	}
	sort(ang.begin(),ang.end());
	ang.push_back(make_pair(ang[0].first + 2 * PI, ang[0].second) );
	int ans = 0;
	long double Max = 1e9*1.0; 
	for(int i=0;i<n;i++)
	{
		auto tmp_ang = ang[i+1].first - ang[i].first;
		if(tmp_ang < Max)
		{
			Max = tmp_ang;
			ans = i;
		}
	}
	cout << ang[ans].second << " " << ang[ans+1].second <<endl;
	return 0;
}