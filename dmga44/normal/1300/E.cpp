#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;
#define MAXN 1000005
#define eps (ld)(1e-9)

int xs[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    cout.tie(0);

    int n;
//    cin >> n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
//        cin >> xs[i];
        scanf("%d",&xs[i]);

    vector<pdi> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].first=xs[i];
        v[i].second=1;
    }

    bool ok=1;
    while(ok)
    {
        ok=0;
        ld sum=0;
        int cant=0;
        vector<pdi> vv;
        for(int i=0;i<v.size();i++)
        {
            if(i && v[i].first>(sum/(double)cant))
            {
                if(cant!=0 && ((sum/(double)cant)>v[i-1].first+eps || (sum/(double)cant)<v[i-1].first-eps))
                    ok=1;
                vv.push_back(pdi((sum/(double)cant),cant));
                sum=0;
                cant=0;
            }
            sum+=v[i].first*v[i].second;
            cant+=v[i].second;
        }
        if(cant!=0 && ((sum/(double)cant)>v[v.size()-1].first+eps || (sum/(double)cant)<v[v.size()-1].first-eps))
            ok=1;
        vv.push_back(pdi((sum/(double)cant),cant));

        v.clear();
        for(auto y : vv)
            v.push_back(y);

        sum=cant=0;
        vv.clear();
        for(int i=v.size()-1;i>=0;i--)
        {
            if(i!=v.size()-1 && v[i].first<(sum/(double)cant))
            {
                if(cant!=0 && ((sum/(double)cant)>v[i+1].first+eps || (sum/(double)cant)<v[i+1].first-eps))
                    ok=1;
                vv.push_back(pdi((sum/(double)cant),cant));
                sum=0;
                cant=0;
            }
            sum+=v[i].first*v[i].second;
            cant+=v[i].second;
        }
        if(cant!=0 && ((sum/(double)cant)>v[0].first+eps || (sum/(double)cant)<v[0].first-eps))
            ok=1;
        vv.push_back(pdi((sum/(double)cant),cant));

        reverse(vv.begin(),vv.end());

        v.clear();
        for(auto y : vv)
            v.push_back(y);
    }

//    cout.precision(9);
//    cout<<fixed;

    for(int i=0;i<v.size();i++)
//        db(a[i])
        for(int j=0;j<v[i].second;j++)
            printf("%.9f\n",v[i].first);

    return 0;
}