#include <bits/stdc++.h>

using namespace std;

const int N=(int)1e4+1;
string a;
int n;
bool ok[2][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    n=a.size();
    a="x"+a;
    ok[0][n-1]=1;
    ok[1][n-2]=1;
    for(int i=n;i>=6;i--)
    {
        string x2;
        x2+=a[i-2];
        x2+=a[i-1];
        string x3;
        x3+=a[i-3];
        x3+=a[i-2];
        x3+=a[i-1];
        if(ok[0][i] && i+1<=n)
        {
            string n2;
            n2+=a[i];
            n2+=a[i+1];
            if(n2!=x2)
            {
                ok[0][i-2]=1;
            }
            ok[1][i-3]=1;
        }
        if(ok[1][i] && i+2<=n)
        {
            string n3;
            n3+=a[i];
            n3+=a[i+1];
            n3+=a[i+2];
            if(n3!=x3)
            {
                ok[1][i-3]=1;
            }
            ok[0][i-2]=1;
        }
    }
    set<string>s;
    for(int i=6;i<=n;i++)
    {
        string x2;
        x2+=a[i];
        x2+=a[i+1];
        string x3;
        x3+=a[i];
        x3+=a[i+1];
        x3+=a[i+2];
        if(ok[0][i])
        {
            s.insert(x2);
        }
        if(ok[1][i])
        {
            s.insert(x3);
        }
    }
    cout<<s.size()<<"\n";
    for(auto x:s)
    {
        cout<<x<<"\n";
    }
    return 0;
}