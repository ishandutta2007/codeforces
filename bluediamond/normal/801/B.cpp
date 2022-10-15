#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b;
    cin>>a>>b;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        int x=a[i]-'a';
        int y=b[i]-'a';
        if(x<y)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<b<<"\n";
    return 0;
}