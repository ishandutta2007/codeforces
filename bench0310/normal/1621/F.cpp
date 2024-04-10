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
        ll res=0;
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        string tmp;
        cin >> tmp;
        auto go=[&](int tp,multiset<int> s,int merger,int ones,int side_zeroes,int non_merger)
        {
            ll now=0;
            auto mv=[&]()
            {
                int sz=(*s.begin());
                s.erase(s.begin());
                sz--;
                if(sz>1) s.insert(sz);
                else merger++;
                now+=a;
            };
            while(1)
            {
                if(tp==0)
                {
                    if(ones>0)
                    {
                        if(!s.empty()) mv();
                        else if(side_zeroes>0)
                        {
                            side_zeroes--;
                            now+=a;
                        }
                        else if(merger>0)
                        {
                            merger--;
                            ones++;
                            now-=c;
                        }
                        else if(non_merger>0)
                        {
                            non_merger--;
                            now-=c;
                        }
                        else break;
                    }
                    else
                    {
                        if(!s.empty()||side_zeroes>0) res=max(res,now+a);
                        if(merger>0)
                        {
                            merger--;
                            ones++;
                            now-=c;
                        }
                    }
                }
                else
                {
                    if(ones==0) break;
                    ones--;
                    now+=b;
                }
                res=max(res,now);
                tp^=1;
            }
        };
        multiset<int> s;
        int merger=0;
        int ones=0;
        int side_zeroes=0;
        int l_one=-1,r_one=-1;
        int non_merger=0;
        for(int i=0;i<n;i++)
        {
            if(tmp[i]=='1')
            {
                if(l_one==-1) l_one=i;
                r_one=max(r_one,i);
                ones+=(i+1<n&&tmp[i+1]=='1');
            }
        }
        if(l_one!=-1)
        {
            side_zeroes=max(0,l_one-1)+max(0,n-r_one-2);
            non_merger=((l_one!=0)+(r_one!=n-1));
            int l=l_one;
            while(l<r_one)
            {
                if(tmp[l]=='1')
                {
                    l++;
                    continue;
                }
                int r=l;
                while(tmp[r+1]=='0') r++;
                if(l==r) merger++;
                else s.insert(r-l+1);
                l=r+1;
            }
            for(int tp=0;tp<2;tp++) go(tp,s,merger,ones,side_zeroes,non_merger);
        }
        else res=(n>=2?a:0);
        cout << res << "\n";
    }
    return 0;
}