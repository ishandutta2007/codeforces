#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    string cur;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='W' && a[i+1]=='U' && a[i+2]=='B')
        {
            if(cur!="")
                cout<<cur<<" ";
            cur="";
            i+=2;
            continue;
        }
        cur+=a[i];
    }
    if(cur!="")
        cout<<cur;
    cout<<"\n";
    return 0;
}
/**

**/