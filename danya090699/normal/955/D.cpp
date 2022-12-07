#include <bits/stdc++.h>
using namespace std;
void find_zf(string &s, string &t, int *z)
{
    int m=t.size();
    string ss=t+"#"+s;
    int zf[ss.size()], l=0, r=0;
    zf[0]=0;
    for(int a=1; a<ss.size(); a++)
    {
        zf[a]=0;
        if(r>a) zf[a]=min(r-a, zf[a-l]);
        while(a+zf[a]<ss.size())
        {
            if(ss[zf[a]]==ss[a+zf[a]]) zf[a]++;
            else break;
        }
        if(a+zf[a]>r)
        {
            r=a+zf[a], l=a;
        }
        if(a>m) z[a-m-1]=zf[a];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    string s, t;
    cin>>s>>t;
    int zf[n], zf2[n], fo=0;
    find_zf(s, t, zf);
    string s2, t2;
    for(int a=n-1; a>=0; a--) s2.push_back(s[a]);
    for(int a=m-1; a>=0; a--) t2.push_back(t[a]);
    find_zf(s2, t2, zf2);
    reverse(zf2, zf2+n);
    for(int a=0; a<n; a++)
    {
        if(zf[a]==m)
        {
            int l=max(0, a-(2*k-m));
            cout<<"Yes\n"<<l+1<<" "<<l+k+1;
            fo=1;
            break;
        }
    }
    if(fo==0)
    {
        map <int, int> ma;
        set <int> us;
        for(int a=k; a>=0; a--) us.insert(us.begin(), a);
        for(int a=0; a<n; a++)
        {
            int i=a-m+1;
            if(i>=0)
            {
                int l=max(0, k-i), r=min(k, zf[i]);
                if(l<=r)
                {
                    auto it=us.lower_bound(l);
                    auto st=it;
                    for(it; it!=us.end(); it++)
                    {
                        int le=(*it);
                        if(le>r) break;
                        ma[le]=i;
                    }
                    us.erase(st, it);
                }
            }
            int l=max(0, k-(n-a-1)), r=min(k, zf2[a]);
            if(l<=r)
            {
                l=m-l, r=m-r, swap(l, r);
                auto it=ma.lower_bound(l);
                if(it!=ma.end())
                {
                    int le=(*it).first, i=(*it).second;
                    if(le<=r)
                    {
                        cout<<"Yes\n"<<i-(k-le)+1<<" "<<a-(m-le)+2;
                        fo=1;
                        break;
                    }
                }
            }
        }
    }
    if(fo==0) cout<<"No";
}