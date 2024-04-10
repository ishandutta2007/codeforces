#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back

const int N=1e6+5;
bool p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2;i<N;i++) p[i]=1;
    for(int i=4;i<N;i+=2) p[i]=0;
    for(int i=3;i*i<N;i+=2)
        if(p[i])
            for(int j=i*i;j<N;j+=2*i)
                p[j]=0;
    int q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        ll r=sqrt(x);
        if(r*r==x && p[r])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
/**



**/