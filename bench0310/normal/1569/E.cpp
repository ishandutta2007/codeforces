#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    ll h;
    vector<int> v;
    obj(ll _h){h=_h;}
    obj(ll _h,vector<int> _v){h=_h;v=_v;}
    bool operator<(const obj &o){return (h<o.h);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    ll p,h;
    cin >> k >> p >> h;
    vector<ll> pw((1<<k)+1,1);
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    for(int i=1;i<=(1<<k);i++) pw[i]=mul(pw[i-1],p);
    vector<ll> score(k+1,0);
    score[0]=1;
    for(int i=1;i<=k;i++) score[i]=((1<<(i-1))+1);
    vector<ll> val(k+1,0);
    for(int i=0;i<=k;i++) val[i]=pw[score[i]];
    auto go=[&](int l,int win)->vector<obj>
    {
        vector<obj> tmp;
        int teams=(1<<(k-1));
        vector<int> team_id(teams,0);
        for(int i=0;i<teams;i++) team_id[i]=l+i;
        int games=((1<<(k-1))-1);
        for(int m=0;m<(1<<games);m++)
        {
            vector<int> fin(teams,0);
            int game=0;
            vector<int> tournament;
            ll t=0;
            for(int i=0;i<teams;i++) tournament.push_back(i);
            int lvl=k;
            while(tournament.size()>1)
            {
                int sz=tournament.size();
                vector<int> nxt;
                for(int i=0;i<sz;i+=2)
                {
                    int x=tournament[i];
                    int y=tournament[i+1];
                    if(m&(1<<game)) swap(x,y);
                    nxt.push_back(x);
                    fin[y]=score[lvl];
                    t=add(t,mul(team_id[y],val[lvl]));
                    game++;
                }
                tournament=nxt;
                lvl--;
            }
            assert(game==games);
            int winner=tournament[0];
            int wlvl=1-win;
            fin[winner]=score[wlvl];
            t=add(t,mul(team_id[winner],val[wlvl]));
            tmp.push_back(obj(t,fin));
        }
        return tmp;
    };
    auto ch=[&](int win)
    {
        vector<obj> one=go(1,win);
        vector<obj> two=go((1<<(k-1))+1,!win);
        sort(two.begin(),two.end());
        for(obj &o:one)
        {
            ll t=sub(h,o.h);
            auto it=lower_bound(two.begin(),two.end(),obj(t));
            if(it!=two.end()&&(*it).h==t)
            {
                for(int z:o.v) cout << z << " ";
                for(int z:(*it).v) cout << z << " ";
                cout << "\n";
                exit(0);
            }
        }
    };
    ch(0);
    ch(1);
    cout << "-1\n";
    return 0;
}