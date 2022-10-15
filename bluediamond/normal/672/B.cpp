#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int n;
string a;

int ap[30],cnt=0,gol=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a;
    for(int i=0;i<n;i++)
        ap[a[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(ap[i]==0)
            gol++;
        else
            cnt+=ap[i]-1;
    }
    if(cnt<=gol)
        cout<<cnt<<"\n";
    else
        cout<<"-1\n";
    return 0;
}
/**
**/