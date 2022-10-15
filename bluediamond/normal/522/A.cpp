#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<string,int>l;

string rep(string a)
{
    string res;
    for(auto &it:a)
    {
        if('A'<=it && it<='Z')
        {
            res+=(it-'A'+'a');
        }
        else
        {
            res+=it;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,res=0;
    cin>>n;
    while(n--)
    {
        string a,useless,b;
        cin>>a>>useless>>b;
        a=rep(a);
        b=rep(b);
        l[a]=1+l[b];
        res=max(res,l[a]);
    }
    res++;
    cout<<res<<"\n";
    return 0;
}
/**


**/