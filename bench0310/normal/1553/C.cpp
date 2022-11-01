#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int res=10;
        function<void(int,int,int,int,int)> go=[&](int mv,int a,int b,int aleft,int bleft)
        {
            if(a+aleft<b||b+bleft<a) res=min(res,mv);
            if(mv==10) return;
            int xa=((mv%2)==0);
            int xb=((mv%2)==1);
            if(s[mv]=='0'||s[mv]=='?') go(mv+1,a,b,aleft-xa,bleft-xb);
            if(s[mv]=='1'||s[mv]=='?') go(mv+1,a+xa,b+xb,aleft-xa,bleft-xb);
        };
        go(0,0,0,5,5);
        cout << res << "\n";
    }
    return 0;
}