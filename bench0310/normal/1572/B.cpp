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
        int s=0,c=0;
        vector<array<int,3>> v;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a==1)
            {
                if(c==0) s=i;
                c++;
            }
            else if(c!=0)
            {
                v.push_back({s,i-1,c&1});
                c=0;
            }
        }
        if(c!=0) v.push_back({s,n,c&1});
        vector<int> res;
        bool ok=[&]()->bool
        {
            if(v.empty()) return 1;
            if(v[0]==array<int,3>{1,n,n&1}) return 0;
            int sz=v.size();
            bool odd=0;
            int one=0;
            if(v[0][0]==1)
            {
                if(v[0][2]==0)
                {
                    for(int i=v[0][1]-1;i>=1;i-=2) res.push_back(i);
                }
                else odd=1;
            }
            int tr=0;
            if(odd==1) tr=v[0][1];
            for(int i=(v[0][0]==1);i<sz;i++)
            {
                auto [l,r,o]=v[i];
                if(odd==0)
                {
                    if(one==0)
                    {
                        for(int j=l-1;j+2<=r;j+=2) res.push_back(j);
                        if(o==1) one=r;
                    }
                    else
                    {
                        while(one<l-2)
                        {
                            res.push_back(one);
                            res.push_back(one-1);
                            one+=2;
                        }
                        if(one==l-2)
                        {
                            res.push_back(one);
                            l++;
                        }
                        else l--;
                        o^=1;
                        one=0;
                        for(int j=l-1;j+2<=r;j+=2) res.push_back(j);
                        if(o==1) one=r;
                    }
                }
                else
                {
                    if(o==0)
                    {
                        if(l&1)
                        {
                            for(int j=l-2;j>=tr+2;j-=2) res.push_back(j);
                            res.push_back(tr);
                            for(int j=tr-2;j>=1;j-=2) res.push_back(j);
                            for(int j=tr+2;j+3<=r;j+=2) res.push_back(j);
                            one=r;
                            odd=0;
                        }
                        else
                        {
                            for(int j=l-2;j>=tr+1;j-=2) res.push_back(j);
                            tr=r;
                        }
                    }
                    else
                    {
                        if(r==n)
                        {
                            if(((l-tr)%2)==0)
                            {
                                for(int j=l-2;j>=tr+2;j-=2) res.push_back(j);
                                res.push_back(tr);
                                for(int j=tr-2;j>=1;j-=2) res.push_back(j);
                                for(int j=tr+2;j+2<=n;j+=2) res.push_back(j);
                                odd=0;
                            }
                            else return 0;
                        }
                        else
                        {
                            for(int j=r-1;j>=l+1;j-=2) res.push_back(j);
                            int x=l;
                            while(x>tr+2)
                            {
                                res.push_back(x-2);
                                res.push_back(x-1);
                                x-=2;
                            }
                            if(x==tr+2)
                            {
                                res.push_back(tr);
                                for(int j=tr-2;j>=1;j-=2) res.push_back(j);
                            }
                            else
                            {
                                for(int j=tr;j>=1;j-=2) res.push_back(j);
                            }
                            odd=0;
                        }
                    }
                }
            }
            if(odd==1||one!=0) return 0;
            return 1;
        }();
        if(ok)
        {
            cout << "YES\n";
            cout << res.size() << "\n";
            for(int b:res) cout << b << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}