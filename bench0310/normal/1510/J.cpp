#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<int> l={0},r={0};
    int idx=1;
    while(idx<=n)
    {
        if(s[idx]=='_')
        {
            idx++;
            continue;
        }
        l.push_back(idx);
        while(idx+1<=n&&s[idx+1]=='#') idx++;
        r.push_back(idx++);
    }
    auto out=[&](vector<int> res)
    {
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
        exit(0);
    };
    int k=l.size()-1;
    if(k==0) out({});
    int lim=min(l[1]-1,n-r[k]);
    for(int i=1;i<k;i++) lim=min(lim,l[i+1]-r[i]-2);
    auto rev=[&](vector<int> v,int sz)
    {
        vector<int> res;
        int p=0;
        for(int i=1;i<=sz;i++)
        {
            if(v[i]==0)
            {
                res.push_back(i-p-1);
                p=i;
            }
        }
        res.push_back(sz-p);
        out(res);
    };
    auto check_zero_one=[&](int mv,vector<int> v)
    {
        int sz=n-mv;
        v.push_back(0);
        if(mv==1)
        {
            for(int i=1;i<=sz;i++)
            {
                if(v[i-1]+v[i]+v[i+1]==0) v[i]=1;
            }
        }
        if(v[1]==0||v[sz]==0) return;
        for(int i=1;i<sz;i++) if(v[i]==0&&v[i+1]==0) return;
        rev(v,sz);
    };
    auto check_mv=[&](int mv,vector<int> v)
    {
        int sz=n-mv;
        vector<int> t={1};
        int id=1;
        while(id<=sz)
        {
            if(v[id]==0)
            {
                id++;
                continue;
            }
            t.push_back(id-2);
            while(id+1<=sz&&v[id+1]==1) id++;
            t.push_back(id+2);
            id++;
        }
        t.push_back(sz);
        for(int i=0;i<(int)t.size();i+=2)
        {
            int x=t[i];
            int y=t[i+1];
            if(x>y) continue;
            if(((y-x+1)%2)==0)
            {
                v[x]=v[x+1]=1;
                x+=3;
            }
            for(int j=x;j<=y;j+=2) v[j]=1;
        }
        rev(v,sz);
    };
    auto go=[&](int mv)
    {
        vector<int> v(n-mv+1,0);
        for(int i=1;i<=k;i++) for(int j=l[i]-mv;j<=r[i];j++) v[j]=1;
        if(mv<=1) check_zero_one(mv,v);
        else check_mv(mv,v);
    };
    vector<bool> bad(n+1,0);
    if(l[1]-2>=0) bad[l[1]-2]=1;
    if(n-r[k]-1>=0) bad[n-r[k]-1]=1;
    for(int i=1;i<k;i++) if(l[i+1]-r[i]-3>=0) bad[l[i+1]-r[i]-3]=1;
    for(int mv=0;mv<=lim;mv++) if(mv<=1||bad[mv]==0) go(mv);
    cout << "-1\n";
    return 0;
}