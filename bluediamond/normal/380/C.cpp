#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct kek
{
        int sl;
        int la;
        int lb;
};

kek Merge(kek f,kek s)
{
        int add=min(f.la,s.lb);
        return {f.sl+s.sl+2*add,f.la+s.la-add,f.lb+s.lb-add};
}

const int N=(int)1e6+7;
string s;

int n;
kek t[4*N];

void build(int v,int tl,int tr)
{
        if(tl==tr)
        {
                if(s[tl-1]=='(')
                {
                        t[v].la=1;
                }
                else
                {
                        t[v].lb=1;
                }
        }
        else
        {
                int m=(tl+tr)>>1;
                build(2*v,tl,m);
                build(2*v+1,m+1,tr);
                t[v]=Merge(t[2*v],t[2*v+1]);
        }
}

kek a;
bool fi;

void ask(int v,int tl,int tr,int l,int r)
{
        if(tr<l || r<tl) return;
        if(l<=tl && tr<=r)
        {
                if(fi)
                {
                        fi=0;
                        a=t[v];
                }
                else
                {
                        a=Merge(a,t[v]);
                }
        }
        else
        {
                int m=(tl+tr)>>1;
                ask(2*v,tl,m,l,r);
                ask(2*v+1,m+1,tr,l,r);
        }
}

int gt(int l,int r)
{
        fi=1;
        a.la=a.lb=a.sl=0;
        ask(1,1,n,l,r);
        return a.sl;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>s;
        n=s.size();
        build(1,1,n);
        int q;
        cin>>q;
        while(q--)
        {
                int l,r;
                cin>>l>>r;
                cout<<gt(l,r)<<"\n";
        }
        return 0;
}
/**

**/