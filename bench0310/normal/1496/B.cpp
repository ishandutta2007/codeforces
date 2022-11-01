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
        int n,k;
        cin >> n >> k;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        int mex=0;
        auto mv=[&](){while(s.find(mex)!=s.end()) mex++;};
        auto mx=[&]()->int{return (*s.rbegin());};
        while(k>0&&(int)s.size()<mx()+1)
        {
            mv();
            int x=(mex+mx()+1)/2;
            if(s.find(x)!=s.end()) break;
            s.insert(x);
            k--;
        }
        int res=s.size();
        if((int)s.size()==mx()+1) res+=k;
        cout << res << "\n";
    }
    return 0;
}