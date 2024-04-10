#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    string s, t;
    cin>>n>>m>>q>>s>>t;
    bool us[n];
    for(int a=0; a<n; a++)
    {
        if(a+m<=n)
        {
            if(s.substr(a, m)==t) us[a]=1;
            else us[a]=0;
        }
        else us[a]=0;
    }
    for(int a=0; a<q; a++)
    {
        int l, r, an=0;
        scanf("%d%d", &l, &r);
        l--;
        for(int b=l; b+m<=r; b++) an+=us[b];
        printf("%d\n", an);
    }
}