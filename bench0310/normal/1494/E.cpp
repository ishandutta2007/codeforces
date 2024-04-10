#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int,int> v[n+1];
    auto col=[&](int a,int b)->int
    {
        auto it=v[a].find(b);
        if(it!=v[a].end()) return (it->second);
        else return 0;
    };
    int con=0;
    int eq=0;
    auto add=[&](array<int,2> x)
    {
        con++;
        eq+=(x[0]==x[1]);
    };
    auto rm=[&](array<int,2> x)
    {
        con--;
        eq-=(x[0]==x[1]);
    };
    while(m--)
    {
        char t;
        cin >> t;
        if(t=='+'||t=='-')
        {
            int a,b;
            cin >> a >> b;
            if(t=='+')
            {
                char z;
                cin >> z;
                int c=(z-'a'+1);
                v[a][b]=c;
                int d=col(b,a);
                if(d!=0) add({c,d});
            }
            if(t=='-')
            {
                int c=col(a,b);
                v[a][b]=0;
                int d=col(b,a);
                if(d!=0) rm({c,d});
            }
        }
        else
        {
            int k;
            cin >> k;
            k--;
            if(((k%2)==1&&eq>=1)||(((k%2)==0)&&con>=1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}