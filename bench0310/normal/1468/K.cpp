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
        array<int,2> res={0,0};
        auto go=[&](int x,int y)
        {
            if(x==0&&y==0) return;
            int a=0,b=0;
            array<int,2> bad={x,y};
            for(char c:s)
            {
                if(c=='L'&&array<int,2>{a-1,b}!=bad) a--;
                if(c=='R'&&array<int,2>{a+1,b}!=bad) a++;
                if(c=='D'&&array<int,2>{a,b-1}!=bad) b--;
                if(c=='U'&&array<int,2>{a,b+1}!=bad) b++;
            }
            if(a==0&&b==0) res={x,y};
        };
        int a=0,b=0;
        auto fix=[&]()
        {
            go(a-1,b);
            go(a+1,b);
            go(a,b-1);
            go(a,b+1);
        };
        fix();
        for(char c:s)
        {
            if(c=='L') a--;
            if(c=='R') a++;
            if(c=='D') b--;
            if(c=='U') b++;
            fix();
        }
        cout << res[0] << " " << res[1] << "\n";
    }
    return 0;
}