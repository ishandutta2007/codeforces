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
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int &x:a) cin >> x;
        for(int &x:b) cin >> x;
        vector<int> len={n};
        int res=0;
        for(int o=29;o>=0;o--)
        {
            bool ok=1;
            vector<int> na,nb,nlen;
            int s=0;
            for(int l:len)
            {
                vector<int> nx[2];
                for(int i=s;i<s+l;i++) nx[(a[i]>>o)&1].push_back(a[i]);
                vector<int> ny[2];
                for(int i=s;i<s+l;i++) ny[(b[i]>>o)&1].push_back(b[i]);
                if(nx[0].size()==ny[1].size())
                {
                    for(int x:nx[0]) na.push_back(x);
                    for(int x:nx[1]) na.push_back(x);
                    for(int x:ny[1]) nb.push_back(x);
                    for(int x:ny[0]) nb.push_back(x);
                    int sa=nx[0].size();
                    int sb=nx[1].size();
                    if(sa>0) nlen.push_back(sa);
                    if(sb>0) nlen.push_back(sb);
                }
                else ok=0;
                s+=l;
            }
            if(ok)
            {
                res+=(1<<o);
                a=na;
                b=nb;
                len=nlen;
            }
        }
        cout << res << "\n";
    }
    return 0;
}