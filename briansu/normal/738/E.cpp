#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef multiset<int>::iterator stit;
typedef long long ll;
using namespace std;

multiset<int> d;
int n,s;
ll tt=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>s;
    s--;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(i!=s&&tmp==0){tmp=n+1;}
        else if(i==s&&tmp!=0){tmp=0;tt++;}
        d.insert(tmp);
    }
    int now=0;
    for(;d.count(now);now++);
    now++;
    while(1)
    {
        stit it=d.lower_bound(now);
        if(it==d.end())break;
        stit itb=d.end();
        itb--;
        d.erase(itb);
        d.insert(now-1);
        for(;d.count(now);now++);
        now++;
        tt++;
    }
    cout<<tt<<endl;
}