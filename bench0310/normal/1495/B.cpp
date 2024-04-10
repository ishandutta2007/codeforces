#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    multiset<int> s;
    int c=0;
    for(int i=2;i<=n;i++)
    {
        if(i==2||(p[i-2]<p[i-1])==(p[i-1]<p[i])) c++;
        else
        {
            s.insert(c);
            c=1;
        }
    }
    s.insert(c);
    int res=0;
    for(int i=2;i<n;i++)
    {
        if(!(p[i-1]<p[i]&&p[i]>p[i+1])) continue;
        int x=i-1,y=i+1;
        while(x-1>=1&&p[x]>p[x-1]) x--;
        while(y+1<=n&&p[y]>p[y+1]) y++;
        int a=i-x;
        int b=y-i;
        if(a==b&&((a%2)==0))
        {
            s.erase(s.find(a));
            s.erase(s.find(b));
            if(!s.empty()&&(*s.rbegin())>=a) res+=0;
            else res++;
            s.insert(a);
            s.insert(b);
        }
    }
    cout << res << "\n";
    return 0;
}