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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string res="";
    for(int i=0;i<n;i++)
    {
        string add=" ";
        add[0]=s[i];
        if(!(res.size()&1))
            res+=add;
        else if(s[i]!=res[res.size()-1])
            res+=add;
    }
    int r=res.size();
    if(res.size()&1)
        r--;
    db(n-r)
    for(int i=0;i<r;i++)
        cout << res[i];

    return 0;
}