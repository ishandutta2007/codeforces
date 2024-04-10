#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000000;
const int mod=998244353;
vector<int> p(N+1,1);
int add(int a,int b){return a+b-(a+b>=mod?mod:0);}
int sub(int a,int b){return a-b+(a-b<0?mod:0);}

struct obj
{
    int n;
    int e;
    int bad=0;
    vector<array<int,2>> v;
    obj(int _n)
    {
        n=e=_n;
        v.assign(n+1,{0,0});
    }
    bool is_e(int r){return (v[r][0]==0&&v[r][1]==0);}
    bool is_bad(int r){return (v[r][0]>0&&v[r][1]>0);}
    void upd(int r,int d)
    {
        e+=(d*is_e(r));
        bad+=(d*is_bad(r));
    }
    void go(int r,int c,int x,int d)
    {
        x^=((c&1)==0);
        upd(r,-1);
        v[r][x]+=d;
        upd(r,1);
    }
    void add(int r,int c,int x){go(r,c,x,1);}
    void rm(int r,int c,int x){go(r,c,x,-1);}
    int val(){return (bad==0?p[e]:0);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=N;i++) p[i]=add(p[i-1],p[i-1]);
    int n,m,k;
    cin >> n >> m >> k;
    obj row(n);
    obj col(m);
    map<array<int,2>,int> s;
    array<int,2> cnt={0,0};
    auto add_cell=[&](int r,int c,int x)
    {
        cnt[(r+c+x)&1]++;
        row.add(r,c,x);
        col.add(c,r,x);
    };
    auto rm_cell=[&](int r,int c,int x)
    {
        cnt[(r+c+x)&1]--;
        row.rm(r,c,x);
        col.rm(c,r,x);
    };
    auto chess=[&]()
    {
        if(cnt[0]==0&&cnt[1]==0) return 2;
        else if(cnt[0]==0||cnt[1]==0) return 1;
        else return 0;
    };
    while(k--)
    {
        int r,c,t;
        cin >> r >> c >> t;
        if(t>=0)
        {
            if(s.find({r,c})!=s.end()) rm_cell(r,c,s[{r,c}]);
            add_cell(r,c,t);
            s[{r,c}]=t;
        }
        else
        {
            if(s.find({r,c})!=s.end())
            {
                rm_cell(r,c,s[{r,c}]);
                s.erase({r,c});
            }
        }
        cout << sub(add(row.val(),col.val()),chess()) << "\n";
    }
    return 0;
}