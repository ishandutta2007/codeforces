#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 i128;

void in(i128 &a,i128 &b,i128 &c,i128 &d,i128 &e,i128 &f)
{
    ll g,h,i,j,k,l;
    cin >> g >> h >> i >> j >> k >> l;
    a=g;b=h;c=i;d=j;e=k;f=l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i128 k,l,r,t,x,y;
    in(k,l,r,t,x,y);
    auto out=[](bool b)
    {
        if(b==1) cout << "Yes\n";
        else cout << "No\n";
        exit(0);
    };
    if(x>=y)
    {
        if(k+y<=r) k+=y;
        k+=((t-1)*(y-x));
        k-=x;
        out(k>=l);
    }
    if(y>r-l)
    {
        k-=(t*x);
        out(k>=l);
    }
    if(r-y>=l+x-1) out(1);
    if(r-y<k&&k<l+x) out(0);
    auto mv=[&](i128 pos)->array<i128,2> //nxt,days
    {
        //cout << "in " << (ll)pos << endl;
        if(pos+y<=r) pos+=y;
        i128 days=(pos-l)/x;
        i128 nxt=pos-days*x;
        //cout << "days=" << (ll)days << " nxt=" << (ll)nxt << endl;
        return {nxt,days};
    };
    set<i128> s;
    i128 now=k;
    while(1)
    {
        if(s.find(now)!=s.end()) out(1);
        //cout << now << " ";
        auto [nxt,days]=mv(now);
        t-=days;
        if(t<=0) out(1);
        s.insert(now);
        now=nxt;
        if(now>r-y) out(0);
    }
    return 0;
}