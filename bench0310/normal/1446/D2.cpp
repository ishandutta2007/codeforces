#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int K=550;
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> freq(n+1,0);
    vector<int> occ[n+1];
    array<int,2> mx={0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        occ[a[i]].push_back(i);
        mx=max(mx,{freq[a[i]],a[i]});
    }
    int big=mx[1];
    vector<int> cbig(n+1,0);
    for(int i=1;i<=n;i++) cbig[i]=cbig[i-1]+(a[i]==big);
    auto cntbig=[&](int l,int r)->int{return (cbig[r]-cbig[l-1]);};
    vector<int> prv(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        prv[i]=prv[i-1];
        if(a[i]==big) prv[i]=i;
    }
    vector<int> nxt(n+2,-1);
    for(int i=n;i>=1;i--)
    {
        nxt[i]=nxt[i+1];
        if(a[i]==big) nxt[i]=i;
    }
    int res=0;
    auto solve_big=[&](int x)
    {
        vector<int> v(2*n+1,-1);
        v[n]=0;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==big) s++;
            else if(a[i]==x) s--;
            if(v[s+n]!=-1) res=max(res,i-v[s+n]);
            else v[s+n]=i;
        }
    };
    auto solve=[&](int l,int r,vector<array<int,2>> events)
    {
        int d=events.size();
        vector<int> v(2*d+1,-1);
        v[d]=l-1;
        int s=0;
        for(int i=0;i<d;i++)
        {
            s+=events[i][1];
            if(v[s+d]!=-1) res=max(res,(i<d-1?events[i+1][0]-1:r)-v[s+d]);
            else v[s+d]=events[i][0];
        }
    };
    auto get_left=[&](int now,int lim,int k)->vector<array<int,2>>
    {
        vector<array<int,2>> v;
        while(prv[now]!=-1&&prv[now]>=lim&&(int)v.size()<k)
        {
            now=prv[now];
            v.push_back({now,1});
            now--;
        }
        reverse(v.begin(),v.end());
        return v;
    };
    auto get_right=[&](int now,int lim,int k)->vector<array<int,2>>
    {
        vector<array<int,2>> v;
        while(nxt[now]!=-1&&nxt[now]<=lim&&(int)v.size()<k)
        {
            now=nxt[now];
            v.push_back({now,1});
            now++;
        }
        return v;
    };
    auto ins=[](vector<array<int,2>> &one,vector<array<int,2>> two){one.insert(one.end(),two.begin(),two.end());};
    auto solve_small=[&](int x)
    {
        int k=freq[x];
        vector<int> &pos=occ[x];
        int l=0;
        while(l<k)
        {
            int lim=0;
            if(l>0) lim=pos[l-1];
            vector<array<int,2>> v=get_left(pos[l],lim,k);
            int one=1;
            if(!v.empty()) one=prv[v[0][0]-1]+1;
            if(one==0) one=1;
            while(l<k)
            {
                v.push_back({pos[l],-1});
                lim=n;
                if(l+1<k) lim=pos[l+1];
                ins(v,get_right(pos[l],lim,k));
                if(l==k-1||cntbig(pos[l],pos[l+1])>k)
                {
                    int two=n;
                    if(nxt[pos[l]]!=-1) two=nxt[v.back()[0]+1]-1;
                    if(two==-2) two=n;
                    solve(one,two,v);
                    l++;
                    break;
                }
                l++;
            }
        }
    };
    for(int i=1;i<=n;i++)
    {
        if(freq[i]<=K) solve_small(i);
        else solve_big(i);
    }
    cout << res << "\n";
    return 0;
}