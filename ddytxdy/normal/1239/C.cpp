#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,p;LL now,ans[N];
priority_queue<pair<int,int> >q1;
queue<int>q;
priority_queue<int>q2;
int main(){
    scanf("%d%d",&n,&p);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),q1.push(make_pair(-x,-i));
    for(int i=1;i<=n;i++){
        if(q.empty())now=-q1.top().first;now+=p;
        while(q1.size()&&-q1.top().first<=now){
            if(q.empty()||q.back()>-q1.top().second)q.push(-q1.top().second);
            else q2.push(q1.top().second);q1.pop();
        }
        ans[q.front()]=now;q.pop();
        if(q2.size()&&q.empty())q.push(-q2.top()),q2.pop();
    }
    for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
    return 0;
}