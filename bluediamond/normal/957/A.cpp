#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int n;
int v[105];
char s[105];
int main()
{
    cin>>n;
    cin.get();
    cin.getline(s,105);
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='C')v[i]=1;
        if(s[i-1]=='M')v[i]=2;
        if(s[i-1]=='Y')v[i]=3;
        if(s[i-1]=='?')v[i]=0;
    }
    for(int i=1;i<n;i++)
        if(v[i]>0 && v[i+1]>0 && v[i]==v[i+1])
        {
            cout<<"No";
            return 0;
        }
    if(v[1]==0 || v[n]==0)
    {
        cout<<"Yes";
        return 0;
    }
    for(int i=2;i<=n;i++)
        if(v[i-1]==0 && v[i]==0)
        {
            cout<<"Yes";
            return 0;
        }
    for(int i=3;i<n;i++)
        if(v[i-1]==0 && v[i]==0)
        {
            if(v[i-2]==v[i+1])
            {
                cout<<"Yes";
                return 0;
            }
        }
    for(int i=2;i<n;i++)
        if(v[i]==0)
        {
            if(v[i-1]==v[i+1])
            {
                cout<<"Yes";
                return 0;
            }
        }
    cout<<"No";
    return 0;
}
/**


**/