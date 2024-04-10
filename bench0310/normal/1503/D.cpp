#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    int tl=2*n;
    int tr=1;
    vector<int> v(2*n+1,0);
    vector<bool> used(2*n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
        v[a[i]]=v[b[i]]=i;
        tl=min(tl,max(a[i],b[i]));
        tr=max(tr,min(a[i],b[i]));
    }
    if(tl<tr)
    {
        cout << "-1\n";
        exit(0);
    }
    int res=0;
    auto card=[&](int id)->array<int,2>{return {min(a[id],b[id]),max(a[id],b[id])};};
    auto ok1=[&](array<int,3> c,array<int,2> d)->bool
    {
        return ((c[0]<d[0]&&c[1]>d[1])||(c[0]<d[1]&&c[1]>d[0]));
    };
    auto ok2=[&](array<int,2> c,array<int,3> d)->bool
    {
        return ((c[0]<d[0]&&c[1]>d[1])||(c[1]<d[0]&&c[0]>d[1]));
    };
    function<void(int,int)> solve=[&](int l,int r)
    {
        if(l>r) return;
        if(v[l]==v[r])
        {
            used[l]=used[r]=1;
            solve(l+1,r-1);
            return;
        }
        int cnt=0;
        int liml=l;
        int limr=r;
        vector<array<int,3>> one,two;
        auto add=[&](int x,int t)
        {
            int id=v[x];
            cnt++;
            used[a[id]]=used[b[id]]=1;
            array<int,2> c=card(id);
//            cout << "go " << c[0] << " " << c[1] << endl;
            if(one.empty()) one.push_back({c[0],c[1],id});
            else if(two.empty()) two.push_back({c[1],c[0],id});
            else if(t==0&&ok1(one.back(),c))
            {
                if(one.back()[0]<c[0]&&one.back()[1]>c[1]&&c[0]<two.back()[0]&&c[1]>two.back()[1]) one.push_back({c[0],c[1],id});
                else one.push_back({c[1],c[0],id});
            }
            else if(t==1&&ok2(c,two.back()))
            {
                if(c[0]<two.back()[0]&&c[1]>two.back()[1]&&one.back()[0]<c[0]&&one.back()[1]>c[1]) two.push_back({c[0],c[1],id});
                else two.push_back({c[1],c[0],id});
            }
            else
            {
                cout << "-1\n";
                exit(0);
            }
            if(t==0)
            {
                l++;
                limr=min(limr,c[1]);
            }
            else
            {
                r--;
                liml=max(liml,c[0]);
            }
        };
        add(l,0);
        add(r,1);
        while(l<=r)
        {
            bool mv=0;
            while(l<=liml)
            {
                if(used[l]) l++;
                else
                {
                    add(l,0);
                    mv=1;
                    break;
                }
            }
            while(limr<=r)
            {
                if(used[r]) r--;
                else
                {
                    add(r,1);
                    mv=1;
                    break;
                }
            }
            if(mv==0) break;
        }
        int op=0;
        for(auto [x,y,id]:one) op+=(x!=a[id]&&y!=b[id]);
        for(auto [x,y,id]:two) op+=(x!=a[id]&&y!=b[id]);
        res+=min(op,cnt-op);
        reverse(two.begin(),two.end());
        for(auto tmp:two) one.push_back(tmp);
//        cout << "lvl" << endl;
//        for(auto [ta,tb,tid]:one) cout << ta << " " << tb << endl;
        for(int i=0;i<cnt-1;i++)
        {
            if(one[i][0]>=one[i+1][0])
            {
                cout << "-1\n";
                exit(0);
            }
            if(one[i][1]<=one[i+1][1])
            {
                cout << "-1\n";
                exit(0);
            }
        }
        solve(l,r);
    };
    solve(1,2*n);
    cout << res << "\n";
    return 0;
}