#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
const int N = 345;
char s[N][N];
int  dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int  dy[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int  n, m;
void dfs(int x, int y, int& t)
{
    if ((x < 0) || (x >= n) || (y < 0) || (y >= m) || (s[x][y] != '1')) return;
    s[x][y] = '2'; 
	t++;
    for(int i = 0; i < 8; i++)
	{
        dfs(x + dx[i], y + dy[i], t);
    }
}

bool judge(int x, int y, int len, int l, int r)
{
    for(int i = 0; i <= len; i++)
    {
    	for (int j = l; j < r; j++)
		{
            int tx = x + dx[j] * i;
            int ty = y + dy[j] * i;
            if ((tx < 0) || (tx >= n) || (ty < 0) || (ty >= m) || (s[tx][ty] != '2')) return false;
        }
	}       
    return true;
}

int main()
{
    int T;
	cin>>T;
    while (T--)
	{
        int d, sum = 0;
		cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> s[i];
        
        for (int i = 0; i < n; i++)
        {
        	for (int j = 0; j < m; j++)
        	{
        		if (s[i][j] == '1')
				{
					d = 0;
                    dfs(i, j, d);
                    if (d % 4 || (d / 4 > 250)) continue;
                    sum += judge(i, j, d / 4, 0, 2) && judge(i + d / 4, j + d / 4, d / 4, 2, 4);
                    
                    sum += judge(i, j, d / 4, 4, 6) && judge(i + d / 2, j, d / 4, 6, 8);
                }
			}
                
		}    
        cout<<sum<<endl;
    }
    return 0;
}