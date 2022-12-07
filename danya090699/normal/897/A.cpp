#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char s[n];
    for(int a=0; a<n; a++) cin>>s[a];
    for(int a=0; a<m; a++)
    {
        int l, r;
        char sy, sy2;
        cin>>l>>r>>sy>>sy2;
        l--;
        for(l; l<r; l++) if(s[l]==sy) s[l]=sy2;
    }
    for(int a=0; a<n; a++) cout<<s[a];
}