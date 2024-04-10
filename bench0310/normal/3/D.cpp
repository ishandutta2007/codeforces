#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    priority_queue<pair<ll,ll> > p;
    ll x,y,c=0,n=0;
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='(') n++;
        else if(s[i]==')') n--;
        else cin>>x>>y,p.push(make_pair(y-x,i)),s[i]=')',n--,c+=y;
        if(n<0)
        {
            if(p.empty()) break;
            pair<ll,ll> t=p.top();
            p.pop();
            s[t.second]='(';
            n+=2;
            c-=t.first;
        }
    }
    if(n) cout<<-1<<endl;
    else cout<<c<<endl<<s<<endl;
    return 0;
}