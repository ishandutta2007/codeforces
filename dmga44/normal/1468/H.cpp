#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N, K, M;
    	cin >> N >> K >> M;

    	int A[N+2];

    	int arr1[N+2];

    	int arr2[N+2];

    	for(int i = 0 ; i <= N+1 ; i++)
    	{
    		A[i] = 1;
    		arr1[i] = 0;
    		arr2[i] = 0;
    	}

    	for(int i = 0 ; i < M ; i++)
    	{
    		int n;
    		cin >> n;
    		A[n] = 0;
    	}

    	for(int i = 1 ; i <= N ; i++)
    	{
    		arr1[i] += arr1[i-1] + A[i];
    	}

    	for(int i = N ; i >= 1 ; i--)
    	{
    		arr2[i] += arr2[i+1] + A[i];
    	}

    	int sum = 0;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		sum += A[i];
    	}

    	if(sum%(K-1))
    	{
    		cout << "NO" << '\n';
    		continue;
    	}

    	bool flag = false;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		if(A[i] == 0)
    		{
    			if(arr1[i] >= (K-1)/2 && arr2[i] >= (K-1)/2)
    			{
    				flag = true;
    			}
    		}
    	}

    	if(flag)
    	{
    		cout << "YES" << '\n';
    	}
    	else
    	{
    		cout << "NO" << '\n';
    	}
    }

    return 0;
}