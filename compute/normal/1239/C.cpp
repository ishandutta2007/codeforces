#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
typedef pair<ll,int> PII;
ll t[maxn];
struct Event{
    ll te;
    int tp,id;//tp=0 over =1 wt
    bool operator<(const Event &a)const{
        if(te==a.te)
        {
            if(tp==a.tp)
                return id>a.id;
            return tp>a.tp;
        }
        return te>a.te;
    }
};
priority_queue<Event> q;
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t[i]);
        q.push(Event{t[i],1,i});
    }
    ll curt=0;
    set<int> inq;
    queue<int> tq;
    set<int> wt;
    ll qt=0;
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        ll curt=u.te;
        if(u.tp==1)
        {
            //cout<<"insert:"<<u.id<<endl;
            wt.insert(u.id);
        }
        else{
            //cout<<u.id<<endl;
            tq.pop();
            inq.erase(u.id);
            t[u.id]=u.te;
        }
        if(q.size()&&q.top().te==u.te) continue;
        if(!wt.empty())
        {
            int cc=*wt.begin();
            if(inq.empty()||(*inq.begin())>cc)
            {
                if(inq.empty()) qt=curt+p;
                else qt+=p;
                wt.erase(cc);
                inq.insert(cc);
                tq.push(cc);
                q.push(Event{qt,0,cc});
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld%c",t[i],i==n?'\n':' ');
}