#include <bits/stdc++.h>

using namespace std;
long long n, a[100005], s, ps[100005];
map <long long, long long> m, k;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        s+=a[i];
        ps[i+1]=s;
    }
    for(int i=0;i<=n;i++)
    {
        if(ps[i]*2==s)
        {
            cout << "YES";
            return 0;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        m[a[i]]++;
        if(s%2==0 && m[s/2-ps[i]])
        {
            cout << "YES";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        k[a[i]]++;
        if(s%2==0 && k[s/2-ps[n]+ps[i+1]])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}