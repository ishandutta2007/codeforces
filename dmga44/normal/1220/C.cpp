#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int mi=26,n=s.size();
    for(int i=0;i<n;i++)
    {
        int v=s[i]-'a';
        if(mi<v)
            db("Ann")
        else
            db("Mike")
        mi=min(mi,v);
    }

    return 0;
}