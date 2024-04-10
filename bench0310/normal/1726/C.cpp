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
        n*=2;
        string s;
        cin >> s;
        s="$"+s;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        auto find_set=[&](auto &&self,int a)->int
        {
            if(a==p[a]) return a;
            else return p[a]=self(self,p[a]);
        };
        int cc=n;
        auto merge_sets=[&](int a,int b)
        {
            a=find_set(find_set,a);
            b=find_set(find_set,b);
            if(a==b) return;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
            cc--;
        };
        stack<int> pos;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='(')
            {
                pos.push(i);
                if(i>1&&s[i-1]==')') merge_sets(i,i-1);
            }
            else
            {
                int x=pos.top();
                pos.pop();
                merge_sets(x,i);
            }
        }
        cout << cc << "\n";
    }
    return 0;
}