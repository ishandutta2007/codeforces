#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define y1 y12312312
#define int ll

using namespace std;
const int N=201;
const int inf=1e9+3;
const int md=1e9+7;
const ll linf = 1e18;

int n,frst,last;
int l[N],r[N];


set<pair<int,int> > st;

main()
{
    bs
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>l[i]>>r[i];
    }
    for(int i=1;i<=n;++i)
    {
        if(l[i]==0)
        {
            int g=i;
            frst=g;
            last=g;
            while(r[g]!=0)
            {
                g=r[g];
                last=g;
            }
            last=g;
            st.insert(mp(frst,last));
        }
    }
    while(st.size()>1)
    {
        pair<int,int> a=(*st.begin());
        st.erase(st.begin());
        pair<int,int> b=(*st.begin());
        st.erase(st.begin());
        r[a.ss]=b.ff;
        l[b.ff]=a.ss;
        st.insert(mp(a.ff,b.ss));
    }
    for(int i=1;i<=n;++i)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
}