#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    pair <int, int> sh[n], ba[m];
    int an[n];
    for(int a=0; a<n; a++) scanf("%d", &sh[a].first), sh[a].second=a;
    for(int a=0; a<m; a++) scanf("%d%d", &ba[a].first, &ba[a].second);
    sort(sh, sh+n);
    sort(ba, ba+m);
    int yk=0, su=0;
    for(int a=0; a<n; a++)
    {
        while(yk<m and ba[yk].first<=sh[a].first) su+=ba[yk].second, yk++;
        an[sh[a].second]=su;
    }
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}