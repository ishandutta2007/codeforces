#pragma GCC optimize("O3","Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> vect;

void f1()
{
	for(int i = 0 ; i < N ; i++)
	{
		swap(vect[2*i], vect[2*i+1]);
	}
}

void f2()
{
	for(int i = 0 ; i < N ; i++)
	{
		swap(vect[i], vect[i+N]);
	}
}

bool ok()
{
	for(int i = 1 ; i < 2*N ; i++)
	{
		if(vect[i-1] > vect[i])return false;
	}
	return true;
}

int ans = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0 ; i < 2*N ; i++)
    {
    	int n;
    	cin >> n;
    	vect.push_back(n);
    }

    vector<int> temp = vect;

   	for(int i = 0 ; i < 10000 ; i++)
   	{
   		if(ok())
   		{
   			ans = min(ans, i);
   			break;
   		}
   		if(i&1)
   		{
   			f1();
   		}
   		else
   		{
   			f2();
   		}
   	}

   	vect = temp;

   	for(int i = 0 ; i < 10000 ; i++)
   	{
   		if(ok())
   		{
   			ans = min(ans, i);
   			break;
   		}
   		if(i&1)
   		{
   			f2();
   		}
   		else
   		{
   			f1();
   		}
   	}

   	if(ans == 1e9)
   	{
   		cout << -1 << '\n';
   	}
   	else
   	{
   		cout << ans << '\n';
   	}

    return 0;
}