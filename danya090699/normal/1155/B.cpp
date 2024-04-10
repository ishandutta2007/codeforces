#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    int q=0, lef=(n-11)/2, fo=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='8')
        {
            if(lef) lef--;
            else
            {
                if(q<=(n-11)/2) cout<<"YES";
                else cout<<"NO";
                fo=1;
                break;
            }
        }
        else q++;
    }
    if(fo==0) cout<<"NO";
}