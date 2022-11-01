#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target ("avx","avx2")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    map<int,int> m;
    auto primes=[&](int x)->int
    {
        if(m.find(x)!=m.end()) return m[x];
        int y=x;
        int c=0;
        for(int i=2;i*i<=x;i++)
        {
            while((x%i)==0)
            {
                x/=i;
                c++;
            }
        }
        return (m[y]=c+(x>1));
    };
    while(t--)
    {
        int a,b,k;
        cin >> a >> b >> k;
        int pa=primes(a);
        int pb=primes(b);
        bool res=[&]()->bool
        {
            if(k==1)
            {
                if(a==b) return 0;
                else if((a%b)==0||(b%a)==0) return 1;
                else return 0;
            }
            else
            {
                int one=2;
                int two=pa+pb;
                return (one<=k&&k<=two);
            }
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}