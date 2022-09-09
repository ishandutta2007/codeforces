#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long

#define Colten_AC ios_base::sync_with_stdio(false),cin.tie(0)
 
using namespace std;

using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;

signed main(void)
{
	Colten_AC;
	
	int q;
	
	cin >> q;
	
	while(q--)
	{
		int n,k;
		
		cin >> n >> k;
		
		vector <int> a,b;
		
		for(int i=0;i<n;i++)
		{
			int input;
			
			cin >> input;
			
			if( input >= 0 ) a.emplace_back(input);
			else b.emplace_back(input); 
		}
		
		sort(a.begin(),a.end());
		sort(b.rbegin(),b.rend());
		
		int ans = 0;
		
		for(int i=(int)a.size()-1;i>=0;i-=k)
		{
			ans += a[i] * 2;
		}
		
		//cout << b.size() << "\n";
		
		for(int i=(int)b.size()-1;i>=0;i-=k)
		{
			ans += b[i] * -2;
		}
		
		if( b.size() == 0 ) ans -= a[a.size()-1];
		
		else if( a.size() == 0 ) ans -= abs(b[b.size()-1]);
		
		else ans -= max(abs(b[b.size()-1]),a[a.size()-1]);
		
		cout << ans << "\n";
	}
	
	return 0;
}