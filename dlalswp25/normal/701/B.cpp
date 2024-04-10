#include <stdio.h>
#include <iostream>

using namespace std;

bool row[100005], col[100005];

int main()
{
    int n, m;
    int r, c, x, y;
    
    scanf("%d %d", &n, &m);
    r = c = n;
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        
        if(!row[x])
        {
            row[x] = true;
            r--;
        }
        if(!col[y])
        {
            col[y] = true;
            c--;
        }
        cout << (long long)r * c << " ";
    }
    return 0;
}