#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<class T>void err(T x,char c='\n'){cout<<x<<c;}
template<class T,class ...Args>void err(T x,Args ...y){err(x,' ');err(y...);}
const int N=2e5+50;
int n;LL ans,sum;
struct node{
    int a,t;
    bool operator <(const node &b)const{return a<b.a;}
}a[N];
priority_queue<int>q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].a);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
    sort(a+1,a+n+1);q.push(a[1].t);sum+=a[1].t;
    for(int i=2;i<=n;i++){
        int c=a[i].a-a[i-1].a;
        // if(!c)q.push(a[i].t);
        while(c&&q.size()){
            sum-=q.top();ans+=sum;q.pop();c--;
        }
        q.push(a[i].t);sum+=a[i].t;
    }
    while(q.size())sum-=q.top(),ans+=sum,q.pop();
    cout<<ans;
    return 0;
}