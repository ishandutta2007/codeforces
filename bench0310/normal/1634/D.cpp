#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(13);
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct interactor
{
    int n;
    int qc;
    int p;
    vector<int> a;
    int ini()
    {
        n=rng(4,6);
        qc=0;
        a.assign(n+1,0);
        cout << "running [";
        p=rng(1,n);
        for(int i=1;i<=n;i++) if(i!=p) a[i]=rng(1,5);
        for(int i=1;i<=n;i++) cout << a[i] << ",]"[i==n];
        cout << endl;
        return n;
    }
    void bad(string msg){cout << msg << endl;exit(0);}
    int q(int i,int j,int k)
    {
        if(i==j||i==k||j==k) bad("Equal indices in a query");
        qc++;
        if(qc>2*n-2) bad("Too many queries");
        return max({a[i],a[j],a[k]})-min({a[i],a[j],a[k]});
    }
    void ch(int i,int j)
    {
        if(i!=p&&j!=p) bad("Wrong guess");
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
//    interactor in;
    while(tc--)
    {
        auto q=[&](int i,int j,int k)->int
        {
            cout << "? " << i << " " << j << " " << k << endl;
//            return in.q(i,j,k);
            int a;
            cin >> a;
            if(a==-1) exit(0);
            return a;
        };
        int n;
        cin >> n;
//        n=in.ini();
        auto go=[&](int a,int b)
        {
            vector<int> extrema;
            int val=-1;
            for(int i=1;i<=n;i++)
            {
                if(i==a||i==b) continue;
                int t=q(a,b,i);
                if(t>val)
                {
                    extrema={i};
                    val=t;
                }
                else if(t==val) extrema.push_back(i);
            }
            return make_pair(extrema,val);
        };
        auto out=[&](int i,int j){/*in.ch(i,j);*/cout << "! " << i << " " << j << endl;};
        auto [extrema,val]=go(1,2);
        if((int)extrema.size()<n-2)
        {
            int e=0;
            int o=1;
            e=extrema[0];
            tie(extrema,val)=go(e,o);
            if(extrema.size()==1) o=extrema[0];
            out(e,o);
        }
        else
        {
            int x=extrema[0];
            int y=extrema[1];
            auto [nextrema,nval]=go(x,y);
            if(nval<=val) out(1,2);
            else
            {
                if((int)nextrema.size()==n-2) out(x,y);
                else out(nextrema[0],nextrema[0]);
            }
        }
    }
    return 0;
}