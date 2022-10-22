#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 400005

vector<int> fs[25];
ll a[MAXN],c[25],ac[(1<<21)+2][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    ordered_set X;
//    for(int i = 1; i <= 16; i *= 2)
//        X.insert(i);
//    cout << *X.find_by_order(1) << endl; // 2
//    cout << *X.find_by_order(2) << endl; // 4
//    cout << *X.find_by_order(4) << endl; // 16
//    cout << (X.end()==X.find_by_order(6)) << endl; // true
//
//    cout<<X.order_of_key(-5)<<endl;  // 0
//    cout<<X.order_of_key(1)<<endl;   // 0
//    cout<<X.order_of_key(3)<<endl;   // 2
//    cout<<X.order_of_key(4)<<endl;   // 2
//    cout<<X.order_of_key(400)<<endl; // 5
    int n;
//    cin >> n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
//        cin >> a[i];
    {
        scanf("%d",&a[i]);
        for(int j=20;j<25;j++)
            fs[j].push_back(a[i]%(1<<(j+1)));
        for(int j=0;j<20;j++)
            ac[a[i]%(1<<(j+1))+1][j]++;
    }

    for(int i=20;i<25;i++)
        sort(fs[i].begin(),fs[i].end());
    for(int i=0;i<20;i++)
        for(int j=1;j<=(1<<(i+1));j++)
            ac[j][i]+=ac[j-1][i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<20;j++)
        {
            int x1=((1<<(j+1))-1)-(a[i]%(1<<(j+1)));
            int x2=(x1-(1<<j)+1+(1<<(j+1)))%(1<<(j+1));
            c[j]+=ac[x1+1][j];
            c[j]-=ac[x2][j];
            if(x1<x2)
            {
                c[j]+=n;
                if(a[i]%(1<<(j+1))>=x2 || a[i]%(1<<(j+1))<=x1)
                    c[j]--;
            }
            else
            {

                if(a[i]%(1<<(j+1))>=x2 && a[i]%(1<<(j+1))<=x1)
                    c[j]--;
            }
        }
        for(int j=20;j<25;j++)
        {
            int x1=((1<<(j+1))-1)-(a[i]%(1<<(j+1)));
            int x2=(x1-(1<<j)+1+(1<<(j+1)))%(1<<(j+1));
//            c[j]+=fs[j].order_of_key(pii(x1+1,i));
            c[j]+=lower_bound(fs[j].begin(),fs[j].end(),x1+1)-fs[j].begin();
//            c[j]-=fs[j].order_of_key(pii(x2,i));
            c[j]-=lower_bound(fs[j].begin(),fs[j].end(),x2)-fs[j].begin();
//            cout << lower_bound(fs[j].begin(),fs[j].end(),x1+1)-fs[j].begin() << ' '
//                 << lower_bound(fs[j].begin(),fs[j].end(),x2)-fs[j].begin() << '\n';
            if(x1<x2)
            {
                c[j]+=n;
                if(a[i]%(1<<(j+1))>=x2 || a[i]%(1<<(j+1))<=x1)
                    c[j]--;
            }
            else
            {

                if(a[i]%(1<<(j+1))>=x2 && a[i]%(1<<(j+1))<=x1)
                    c[j]--;
            }

//            cout << x1 <<  ' ' << x2 << ' ' << c[j] << '\n';
        }
//        db("")
    }

    ll res=0;
    for(int i=0;i<25;i++)
        if((c[i]/2)&1)
            res+=(1<<i);

//    db(res)
    printf("%d\n",res);

    return 0;
}