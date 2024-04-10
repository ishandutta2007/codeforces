#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 3005

vector<int> ad;
int sad[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int inf=0,sup=0;
    for(int i=0;i<n;i++)
    {
        vector<int> ps;
        for(int j=1;j<n;j++)
            if(s[j-1]=='R' && s[j]=='L')
                ps.push_back(j);
        if(!ps.size())
        {
            inf=i;
            break;
        }

        sad[i]=ps.size();
        for(auto y : ps)
        {
            ad.push_back(y);
            swap(s[y-1],s[y]);
        }
        sup+=ps.size();
    }

    if(inf<=k && k<=sup)
    {
        int pos=0;
        for(int i=0;i<inf;i++)
        {
            if(sup-sad[i]+1>=k)
            {
                sup-=sad[i]-1;
//                cout << sad[i] << ' ';
                printf("%d ",sad[i]);
                for(int j=0;j<sad[i];j++)
                {
                    printf("%d ",ad[pos]);
//                    cout << ad[pos] << ' ';
                    pos++;
                }
//                cout << '\n';
                printf("\n");
            }
            else
            {
//                cout << sup-k+1 << ' ';
                printf("%d ",sup-k+1);
                for(int j=0;j<=sup-k;j++)
                {
                    printf("%d ",ad[pos]);
//                    cout << ad[pos] << ' ';
                    pos++;
                }
//                cout << '\n';
                printf("\n");

                for(int j=pos;j<ad.size();j++)
                {
//                    cout << 1 << ' ' << ad[j] << '\n';
                    printf("1 %d\n",ad[j]);
                }

                break;
            }
        }
    }
    else
        db(-1)

    return 0;
}
/**
4 2
RLRL
**/