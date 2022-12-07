#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size(), yk=0;
    vector <char> t, u;
    char suf[n+1];
    suf[n]='z'+1;
    for(int a=n-1; a>=0; a--) suf[a]=min(s[a], suf[a+1]);
    for(int a=0; a<n*2; a++)
    {
        if(t.size()==0)
        {
            t.push_back(s[yk]), yk++;
        }
        else
        {
            if(t.back()<=suf[yk])
            {
                u.push_back(t.back()), t.pop_back();
            }
            else
            {
                t.push_back(s[yk]), yk++;
            }
        }
    }
    for(int a=0; a<n; a++) cout<<u[a];
}