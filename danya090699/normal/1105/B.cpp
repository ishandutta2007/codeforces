#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map <char, int> ma;
    int yk=0, an=0;
    while(yk<n)
    {
        char cu=s[yk];
        int q=0;
        while(yk<n)
        {
            if(s[yk]==cu) yk++, q++;
            else break;
        }
        ma[cu]+=q/k;
        an=max(an, ma[cu]);
    }
    cout<<an;
}