#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

const int MAXN = 1e5 + 100;

int A[MAXN];

vector<int> arr[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i = 1 ; i <= N ; i++)
    {
    	int n;
    	cin >> n;
    	arr[n].push_back(i);
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	cin >> A[i];
    }

    for(int i = 0 ; i < MAXN ; i++)
    {
    	for(int j = 0 ; j < arr[i].size() ; j++)
    	{
    		arr[i][j] = A[arr[i][j]];
    	}
    }

    set<int> st;

    vector<int> vvv;

    for(int i = 1 ; i <= K ; i++)
    {
    	if(arr[i].size() == 0)
    	{
    		st.insert(i);
    	}

    	sort(arr[i].rbegin(), arr[i].rend());

    	while(arr[i].size() > 1)
    	{
    		vvv.push_back(arr[i].back());
    		arr[i].pop_back();
    	}
    }

    sort(vvv.begin(), vvv.end());

    int res = 0;

    for(int i = 0 ; i < st.size() ; i++)
    {
    	res += vvv[i];
    }

    cout << res << '\n';

    return 0;
}