#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    long long an=0;
    for(int a=0; a<s.size(); a++)
    {
        if((s[a]-'0')%2==0) an+=a+1;
    }
    cout<<an;
}