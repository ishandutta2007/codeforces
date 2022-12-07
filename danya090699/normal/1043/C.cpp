#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), i=0;
    for(int a=1; a<n; a++)
    {
        int cu;
        if(s[a]=='a')
        {
            if(i) cu=0;
            else cu=1;
            i=1;
        }
        else
        {
            if(i) cu=1;
            else cu=0;
            i=0;
        }
        cout<<cu<<" ";
        //i^=cu;
    }
    cout<<i;
}