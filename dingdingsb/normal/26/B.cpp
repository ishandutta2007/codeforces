#include<bits/stdc++.h>
using namespace std;
int ans;
stack<int> s;
string a;
int main()
{
    cin>>a;
    for (int i=0;i<a.size();i++)
        if (a[i]=='(')
            s.push(1);
        else
            if (!s.empty())
                s.pop(),ans+=2;
    cout<<ans;
    return 0;
}