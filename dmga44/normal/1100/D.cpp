#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 1000;

int A[MAXN];
int B[MAXN];

struct qu
{
	int k, x, y;
};

qu query(int a, int b)
{
	cout << a << " " << b << '\n';
	cout.flush();
	int k, x, y;
	cin >> k >> x >> y;
	qu pt = {k,x,y};
	return pt;
}

bool ok(int x, int y)
{
	for(int i = 1 ; i <= 666 ; i++)
	{
		if(A[i] == x && B[i] == y)return true;
	}
	return false;
}

int C[4];

int dx[4] = {1,1,999,999};
int dy[4] = {1,999,999,1};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    cin >> X >> Y;

    for(int i = 1 ; i <= 666 ; i++)
    {
    	cin >> A[i] >> B[i];
    }

    while(1)
    {
    	int nx = 0;
    	int ny = 0;

    	if(X < 500)
    	{
    		nx++;
    	}
    	if(X > 500)
    	{
    		nx--;
    	}

    	if(Y < 500)
    	{
    		ny++;
    	}
    	if(Y > 500)
    	{
    		ny--;
    	}

    	if(!nx && !ny)break;

    	if(ok(X+nx,Y+ny))
    	{
    		X += nx;
    		query(X,Y);
    		return 0;
    	}

    	X += nx;
    	Y += ny;

    	qu pt = query(X,Y);

    	if(pt.k == -1)
    	{
    		return 0;
    	}

    	A[pt.k] = pt.x;
    	B[pt.k] = pt.y;
    }

    for(int i = 1 ; i <= 666 ; i++)
    {
    	if(A[i] < 500 && B[i] < 500)
    	{
    		C[0]++;
    		C[1]++;
    		C[3]++;
    	}
    	if(A[i] < 500 && B[i] > 500)
    	{
    		C[0]++;
    		C[1]++;
    		C[2]++;
    	}
    	if(A[i] > 500 && B[i] < 500)
    	{
    		C[0]++;
    		C[3]++;
    		C[2]++;
    	}
    	if(A[i] > 500 && B[i] > 500)
    	{
    		C[1]++;
    		C[2]++;
    		C[3]++;
    	}
    }

    int may = -1;
    int pos = -1;

    for(int i = 0 ; i < 4 ; i++)
    {
    	if(C[i] > may)
    	{
    		may = C[i];
    		pos = i;
    	}
    }

    int ox = dx[pos];
    int oy = dy[pos];

	while(1)
    {
    	int nx = 0;
    	int ny = 0;

    	if(X < ox)
    	{
    		nx++;
    	}
    	if(X > ox)
    	{
    		nx--;
    	}

    	if(Y < oy)
    	{
    		ny++;
    	}
    	if(Y > oy)
    	{
    		ny--;
    	}

    	if(!nx && !ny)break;

    	if(ok(X+nx,Y+ny))
    	{
    		X += nx;
    		query(X,Y);
    		return 0;
    	}

    	X += nx;
    	Y += ny;

    	qu pt = query(X,Y);

    	if(pt.k == -1)
    	{
    		return 0;
    	}

    	A[pt.k] = pt.x;
    	B[pt.k] = pt.y;
    }

    return 0;
}