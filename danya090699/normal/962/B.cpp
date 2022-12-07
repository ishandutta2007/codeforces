#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int yk=0, an=0;
    while(yk<n)
    {
        if(s[yk]=='*') yk++;
        else
        {
            int st=yk;
            while(yk<n)
            {
                if(s[yk]=='.') yk++;
                else break;
            }
            int q1=(yk-st)/2, q2=(yk-st)-(yk-st)/2;
            if(a>b) swap(a, b);
            an+=min(a, q1)+min(b, q2);
            a-=min(a, q1), b-=min(b, q2);
        }
    }
    cout<<an;
}