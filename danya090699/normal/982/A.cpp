#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=1, yk=0;
    string s;
    cin>>n>>s;
    for(int a=1; a<n; a++) if(s[a]=='1' and s[a-1]=='1') ok=0;
    while(yk<n)
    {
        if(s[yk]=='1') yk++;
        else
        {
            int st=yk;
            while(yk<n)
            {
                if(s[yk]=='0') yk++;
                else break;
            }
            int q=yk-st;
            if(q>2) ok=0;
            else if(q==2)
            {
                if(st==0 or yk==n) ok=0;
            }
            else
            {
                if(st==0 and yk==n) ok=0;
            }
        }
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}