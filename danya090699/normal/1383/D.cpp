#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n][m], an[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) scanf("%d", &ar[a][b]);
    vector <int> rows(1, 0);
    for(int a=0; a<n; a++)
    {
        rows.push_back(0);
        for(int b=0; b<m; b++) rows.back()=max(rows.back(), ar[a][b]);
    }
    sort(rows.begin(), rows.end());
    vector <int> cols(1, 0);
    for(int a=0; a<m; a++)
    {
        cols.push_back(0);
        for(int b=0; b<n; b++) cols.back()=max(cols.back(), ar[b][a]);
    }
    sort(cols.begin(), cols.end());

    int r=-1, c=-1;
    queue <pair <int, int> > qu;
    while(rows.back() or cols.back())
    {
        int val=max(rows.back(), cols.back());
        if(val==rows.back()) r++;
        if(val==cols.back()) c++;
        an[r][c]=val;
        if(val==rows.back())
        {
            for(int a=c-1; a>=0; a--) qu.push({r, a});
            rows.pop_back();
        }
        if(val==cols.back())
        {
            for(int a=r-1; a>=0; a--) qu.push({a, c});
            cols.pop_back();
        }
        for(int a=val-1; a>max(rows.back(), cols.back()); a--)
        {
            an[qu.front().first][qu.front().second]=a;
            qu.pop();
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++) printf("%d ", an[a][b]);
        printf("\n");
    }
}