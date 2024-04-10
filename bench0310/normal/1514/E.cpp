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
        auto cmp=[&](int a,int b)->int
        {
            cout << "1 " << a << " " << b << "\n";
            cout.flush();
            int r;
            cin >> r;
            if(r==-1) exit(0);
            return r;
        };
        auto qtwo=[&](int x,vector<int> q)->int
        {
            cout << "2 " << x << " " << q.size();
            for(int b:q) cout << " " << b;
            cout << "\n";
            cout.flush();
            int r;
            cin >> r;
            if(r==-1) exit(0);
            return r;
        };
        function<vector<int>(int,int)> merge_sort=[&](int l,int r)->vector<int>
        {
            if(l==r) return {l};
            int m=(l+r)/2;
            vector<int> one=merge_sort(l,m);
            vector<int> two=merge_sort(m+1,r);
            vector<int> v;
            int a=0,b=0;
            int x=one.size();
            int y=two.size();
            while(a<x&&b<y)
            {
                if(cmp(one[a],two[b])==1) v.push_back(one[a++]);
                else v.push_back(two[b++]);
            }
            while(a<x) v.push_back(one[a++]);
            while(b<y) v.push_back(two[b++]);
            return v;
        };
        vector<int> v=merge_sort(0,n-1);
        vector<vector<int>> scc;
        for(int a:v)
        {
            vector<int> now;
            while(!scc.empty())
            {
                vector<int> q;
                for(vector<int> &tmp:scc) for(int b:tmp) q.push_back(b);
                if(qtwo(a,q)==1)
                {
                    vector<int> tmp=scc.back();
                    scc.pop_back();
                    for(int b:tmp) now.push_back(b);
                }
                else break;
            }
            now.push_back(a);
            scc.push_back(now);
        }
        vector<vector<bool>> res(n,vector<bool>(n,0));
        int sz=scc.size();
        for(int i=0;i<sz;i++)
        {
            for(int a:scc[i])
            {
                for(int j=i;j<sz;j++)
                {
                    for(int b:scc[j]) res[a][b]=1;
                }
            }
        }
        cout << "3\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout << res[i][j];
            cout << "\n";
        }
        cout.flush();
        int r;
        cin >> r;
        if(r==-1) exit(0);
    }
    return 0;
}