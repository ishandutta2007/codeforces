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
        string s="a";
        int c=1;
        while((int)s.size()<n)
        {
            char x=(c++)+'a';
            char y=(c++)+'a';
            if(n-(int)s.size()==1) s+=x;
            else if(n-(int)s.size()==2) s=(s+x+y);
            else
            {
                string a=s;
                while((int)s.size()+2*(int)a.size()+2>n) a.pop_back();
                s=(a+x+s+y+a);
                if(n-(int)s.size()==1) s+=char(c+'a');
            }
        }
        cout << s << "\n";
    }
    return 0;
}