#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair<int,int> pii;

map<char, pii > mp;

struct cell
{
	int nx, ny;
	int px, py;
	int cx, cy;
};

int n, m;

cell cl[5020];
cell beg[5020];
int nm[5020][5020];

bool vis[5020][5020];
char vs[5020][5020];

int main()
{
    int i, j, k;
    int ii, jj;
    int x, nx, y, ny;

    mp['D'] = make_pair( +1, 0 );
    mp['U'] = make_pair( -1, 0 );
    mp['R'] = make_pair( 0, +1 );
    mp['L'] = make_pair( 0, -1 );

    cin >> n >> m;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%s", vs[i] );
    }
    
	memset( beg, -1, sizeof( beg ) );
	memset( nm, -1, sizeof( nm ) );
	
	k = 0;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( vs[i][j] != '.' )
			{
				nm[i][j] = ++k;
				beg[k].cx = i;
				beg[k].cy = j;
			}
		}
	}
    
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( vs[i][j] == '.' ) continue;
			for ( ii = i-1; ii >= 0; ii-- )
			{
				if ( vs[ii][j] != '.' ) break;
			}
			if ( ii >= 0 )
			{
				beg[nm[i][j]].px = nm[ii][j];
			}
			
			for ( ii = i+1; ii < n; ii++ )
			{
				if ( vs[ii][j] != '.' ) break;
			}
			if ( ii < n )
			{
				beg[nm[i][j]].nx = nm[ii][j];
			}
			
			for ( jj = j-1; jj >= 0; jj-- )
			{
				if ( vs[i][jj] != '.' ) break;
			}
			if ( jj >= 0 )
			{
				beg[nm[i][j]].py = nm[i][jj];
			}
			for ( jj = j+1; jj < m; jj++ )
			{
				if ( vs[i][jj] != '.' ) break;
			}
			if ( jj < m )
			{
				beg[nm[i][j]].ny = nm[i][jj];
			}
			
			//cout << nm[i][j] << " " << beg[nm[i][j]].px << " " << beg[nm[i][j]].nx << " " << beg[nm[i][j]].py << " " << beg[nm[i][j]].ny << endl;
		}
	}

    int be = -1, bb = 0;
//    cout << "AAAA " << beg[nm[0][1]].py << endl;
    for ( i  = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
			if ( vs[i][j] == '.' )
			{
				k = 0;
				if ( k > be )
				{
					be = k;
					bb = 0;
				}
				if ( k == be ) bb++;
				continue;
			}
			for ( ii = 0; ii <= n*m; ii++ )
			{
				cl[ii] = beg[ii];
			}

            k = 0;
            x = i; y = j;
            while ( ( x >= 0 ) && ( x < n ) && ( y >= 0 ) && ( y < m ) && ( vs[x][y] != '.' ) )
            {
				k++;
                nx = mp[ vs[x][y] ].first;
                ny = mp[ vs[x][y] ].second;
                jj = nm[x][y];
                if ( cl[jj].px != -1 )
					cl[cl[jj].px].nx = cl[jj].nx;
                if ( cl[jj].nx != -1 )
					cl[cl[jj].nx].px = cl[jj].px;
                if ( cl[jj].py != -1 )
					cl[cl[jj].py].ny = cl[jj].ny;
                if ( cl[jj].ny != -1 )
					cl[cl[jj].ny].py = cl[jj].py;
//				cout << x << " " << y << " " << jj << " " << cl[jj].px << " " << cl[jj].nx << " " << cl[jj].py << " " << cl[jj].ny << endl;
//				break;
//				cout << "MOVE " << i << " " << j << " " << x << " " << y << " ___ " << nx << " " << ny << endl;
//				cout << jj << " " << cl[jj].ny << " " << cl[nm[0][1]].py << endl;
                if ( nx == 0 )
                {
					if ( ny > 0 )
					{
						if ( cl[jj].ny != -1 )
							y = cl[cl[jj].ny].cy;
						else break;
					}
					else
					{
						if ( cl[jj].py != -1 )
							y = cl[cl[jj].py].cy;
						else break;
					}
				}
				else if ( ny == 0 )
				{
					if ( nx > 0 )
					{
						if ( cl[jj].nx != -1 )
							x = cl[cl[jj].nx].cx;
						else break;
					}
					else
					{
						if ( cl[jj].px != -1 )
							x = cl[cl[jj].px].cx;
						else break;
					}
				}
            }
            
            //cout << i << " " << j << " " << k << endl;

            if ( k > be )
            {
                be = k;
                bb = 0;
            }
            if ( k == be ) bb++;
        }
    }
    printf( "%d %d\n", be, bb );
    return 0;
}