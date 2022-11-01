#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<string> s(n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<m;j++) cnt+=(s[i][j]=='*');
    }
    int e=0;
    auto pos=[&](int id)->char
    {
        int j=(id/n);
        int i=(id%n);
        return s[i][j];
    };
    auto id=[&](int i,int j)->int{return (j*n+i);};
    for(int i=0;i<cnt;i++) e+=(pos(i)=='.');
    while(q--)
    {
        int r,c;
        cin >> r >> c;
        r--; c--;
        if(s[r][c]=='*')
        {
            if(id(r,c)!=cnt-1)
            {
                if(pos(cnt-1)=='.') e--;
                if(id(r,c)<cnt) e++;
            }
            cnt--;
        }
        else
        {
            if(id(r,c)!=cnt)
            {
                if(pos(cnt)=='.') e++;
                if(id(r,c)<cnt) e--;
            }
            cnt++;
        }
        s[r][c]=('*'^'.'^s[r][c]);
        cout << e << "\n";
    }
    return 0;
}