#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, cu=0;
    cin>>n;
    bool ar[n];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        cu=gcd(cu, x);
        ar[a]=x%2;
    }
    cout<<"YES\n";
    if(cu>1) cout<<0;
    else
    {
        int yk=0, an=0;
        while(yk<n)
        {
            if(ar[yk])
            {
                int q=0;
                while(yk<n)
                {
                    if(ar[yk])
                    {
                        yk++, q++;
                    }
                    else break;
                }
                an+=q/2;
                if(q%2) an+=2;
            }
            else yk++;
        }
        cout<<an;
    }
}