#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int n, cu=1;
        cin>>n;
        for(int a=0; a<n; a++)
        {
            int l, r;
            cin>>l>>r;
            if(cu<=r)
            {
                cu=max(l, cu);
                cout<<cu<<" ";
                cu++;
            }
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}