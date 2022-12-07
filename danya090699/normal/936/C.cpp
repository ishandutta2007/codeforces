#include <bits/stdc++.h>
using namespace std;
int n;
vector <char> s, t;
vector <int> an;
void f(int q)
{
    an.push_back(q);
    vector <char> te(s.begin()+n-q, s.end());
    s.erase(s.begin()+n-q, s.end());
    reverse(te.begin(), te.end());
    s.insert(s.begin(), te.begin(), te.end());
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        char x;
        cin>>x;
        s.push_back(x);
    }
    for(int a=0; a<n; a++)
    {
        char x;
        cin>>x;
        t.push_back(x);
    }
    int l=0, ok=1;
    for(int a=0; a<n; a++)
    {
        int p=-1;
        for(int b=0; b<n; b++) if((b<l or b>=l+a) and s[b]==t[a]) p=b;
        if(p==-1)
        {
            ok=0;
            break;
        }
        if(a&1)
        {
            f(n-p-1), f(1), f(p), l=p-a;
        }
        else
        {
            if(p<l)
            {
                f(n-l-a), f(l-p-1+a), f(1), l=0;
            }
            else
            {
                f(n-l-a), p=n-p-1, l=n-a, f(l-p-1+a), f(1), l=0;
            }
        }
    }
    if(ok)
    {
        if(n&1) f(n);
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    }
    else cout<<-1;
}