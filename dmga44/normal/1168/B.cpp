#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

vector<int> v0,v1;
ll pos[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
            v0.push_back(i);
        else
            v1.push_back(i);
    }

    int p0=0,p1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            int l=p0-1,r=p0+1;
            while(l>=0 && r<v0.size())
            {
                if(abs(v0[l]-i)==abs(v0[r]-i))
                    break;
                else if(abs(v0[l]-i)>abs(v0[r]-i))
                    r++;
                else
                    l--;
            }
            if(l>=0 && r<v0.size() && abs(v0[l]-i)==abs(v0[r]-i))
                pos[v0[r]]=max(pos[v0[r]],v0[l]+1ll);
            p0++;
        }
        else
        {
            int l=p1-1,r=p1+1;
            while(l>=0 && r<v1.size())
            {
                if(abs(v1[l]-i)==abs(v1[r]-i))
                    break;
                else if(abs(v1[l]-i)>abs(v1[r]-i))
                    r++;
                else
                    l--;
            }
            if(l>=0 && r<v1.size() && abs(v1[l]-i)==abs(v1[r]-i))
                pos[v1[r]]=max(pos[v1[r]],v1[l]+1ll);
            p1++;
        }
    }

    for(int i=1;i<n;i++)
        pos[i]=max(pos[i],pos[i-1]);

    ll res=0;
    for(int i=0;i<n;i++)
        res+=pos[i];
    db(res)

    return 0;
}