#include<bits/stdc++.h>
using namespace std;
const int N=500005;
#define int long long
typedef pair<int,int> pii;
#define mk make_pair
const int MOD=(int)1e9+7;

void init()
{

}

int n,p,ans[N];
priority_queue<pair<int,int> >q1;
queue<int>q;
priority_queue<int>q2;
bool cmp(pii x,pii y){return x>y;}
void solve()
{
    int now=0;
    scanf("%lld%lld",&n,&p);
    for(int i=1,x;i<=n;i++)scanf("%lld",&x),q1.push(make_pair(-x,-i));
    for(int i=1;i<=n;i++){
        if(q.empty())now=-q1.top().first;now+=p;
        while(q1.size()&&-q1.top().first<=now){
            if(q.empty()||q.back()>-q1.top().second)q.push(-q1.top().second);
            else q2.push(q1.top().second);q1.pop();
        }
        ans[q.front()]=now;q.pop();
        if(q2.size()&&q.empty())q.push(-q2.top()),q2.pop();
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
}