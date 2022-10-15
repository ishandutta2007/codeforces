#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int x=0,y=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if('a'<=a[i] && a[i]<='z')
            x++;
        else
            y++;
    }
    if(y>x)
        for(int i=0;i<a.size();i++)
        {
            if('a'<=a[i] && a[i]<='z')
                cout<<char('A'+a[i]-'a');
            else
                cout<<a[i];
        }
    else
        for(int i=0;i<a.size();i++)
        {
            if('A'<=a[i] && a[i]<='Z')
                cout<<char('a'+a[i]-'A');
            else
                cout<<a[i];
        }
    cout<<"\n";
    return 0;
}
/**

**/