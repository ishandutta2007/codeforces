#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string s;
int n;

string marcelo(int p)
{
    string res="",add=" ";

    int l=p-1,r=n-1,pl=0;
    while(l>=0 || r>=p)
    {
        int v=pl;
        if(l>=0)
        {
            v+=(s[l]-'0');
            l--;
        }
        if(r>=p)
        {
            v+=(s[r]-'0');
            r--;
        }
        pl=v/10;
        add[0]='0'+v%10;
        res=res+add;
    }
    if(pl)
        res=res+"1";
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;
    int mi=0;
    vector<int> pos;
    for(int i=1;i<n;i++)
        if(s[i]!='0')
        {
            if(mi==min(i,n-i))
                pos.push_back(i);
            else if(mi<min(i,n-i))
            {
                mi=min(i,n-i);
                pos.clear();
                pos.push_back(i);
            }
        }

    if(pos.size()==1)
        db(marcelo(pos[0]))
    else
    {
        string s1=marcelo(pos[0]);
        string s2=marcelo(pos[1]);
        if(s1.size()<s2.size())
            db(s1)
        else if(s1.size()>s2.size())
            db(s2)
        else
        {
            if(s1<s2)
                db(s1)
            else
                db(s2)
        }
    }

    return 0;
}