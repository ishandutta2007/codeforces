#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool ip(string a)
{
    string b=a;
    reverse(b.begin(),b.end());
    return (a==b);
}

string ins(int p,string s)
{
    string a;
    for(int i=0;i<s.size();i++)
    {
        if(i==p)
        {
            a+=".";
        }
        a+=s[i];
    }
    if(p==s.size())
    {
        a+=".";
    }
    return a;
}

int inv(int p,int n)
{
    return n-p-1;
}

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        string a=ins(i,s);
       /// cout<<a<<"\n";
        int j=inv(i,a.size());
        if(i==j)
        {
            a[i]='y';
        }
        else
        {
            a[i]=a[j];
        }
        if(ip(a))
        {
            cout<<a<<"\n";
            return 0;
        }
    }
    cout<<"NA\n";
    return 0;
}
/**


**/