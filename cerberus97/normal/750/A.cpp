/*
Author : Cerberus97
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define fast_cin() ios_base::sync_with_stdio(false);

// const int N = ;

int main()
{
	int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 1, j = 5; i <= n and j <= 240-k; ++i)
    {
    	++ans;
    	j += 5*(i+1);
    }

    cout << ans << endl;
	return 0;
}