#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 1e5 + 100;

int A[MAXN];

int D[MAXN];

int T[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N, K;
	cin >> N >> K;

	for(int i = 1 ; i <= N ; i++)
	{
		cin >> A[i];
	}

	for(int i = 1 ; i <= N ; i++)
	{
		cin >> D[i];
	}

	if(K == 0)
	{
		int res = 0;

		int acum = 0;

		for(int i = N ; i >= 1 ; i--)
		{
			acum += A[i];
			res = max(res, acum-D[i]);
		}

		cout << res << '\n';
	}

	if(K == 1)
	{
		int res = 0;

		int men = A[N-1];
		int pos = N-1;

		int acum = A[N]+A[N-1];

		for(int i = N-2 ; i >= 1 ; i--)
		{
			acum += A[i];

			res = max(res, max(0ll,acum-men-D[i]) + max(0ll,men-D[pos]));

			if(A[i] < men)
			{
				men = A[i];
				pos = i;
			}
		}

		int acum2 = 0;

		for(int i = N ; i >= 1 ; i--)
		{
			acum2 += A[i];
			T[i] = max(T[i], acum2-D[i]);
			if(i != N)T[i] = max(T[i], T[i+1]);
		}

		men = 1e18;

		acum = 0;

		for(int i = 1 ; i <= N-1 ; i++)
		{
			acum += A[i];
			men = min(men, D[i]);

			res = max(res, max(0ll,acum-men) + max(0ll,T[i+1]));
		}

		cout << res << '\n';
	}

	if(K > 1)
	{
		int res = 0;

		res = max(res,A[N]-D[N]);

		int men = 1e18;
		int acum = 0;

		for(int i = 1 ; i <= N ; i++)
		{
			acum += A[i];
			if(i!=N)men = min(men, D[i]);
		}

		res = max(res, acum-men);

		cout << res << '\n';
	}

    return 0;
}