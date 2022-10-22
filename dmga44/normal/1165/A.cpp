#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int res=0;
    for(int i=0;i<x;i++)
    {
        int sss=1;
        if(s[n-i-1]=='0')
            sss--;
        if(i==y)
            sss=1-sss;
        res+=sss;
    }
    db(res)

    return 0;
}