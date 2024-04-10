#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<pair<int, int>, int> pt;

bool comp(const pt& a, const pt& b)
{
    if (a.x.x / 1000 != b.x.x / 1000)
        return a.x.x / 1000 < b.x.x / 1000;
    return a.x.y < b.x.y;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pt> z(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &z[i].x.x, &z[i].x.y);
        z[i].y = i + 1;
        z[i].x.x--;
    }
    sort(z.begin(), z.end(), comp);
    for(int i = 0; i < n; i++)
        printf("%d ", z[i].y);
    puts("");
    return 0;
}