#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;

int m,a,b;
int mi[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> >  > q;

void fnd(){
    memset(mi,-1,sizeof(mi));
    q.push(make_pair(0,0));
    while(!q.empty()){
        int cu=q.top().second;
        int cw=q.top().first;
        q.pop();
        if(mi[cu]!=-1)continue;
        mi[cu]=cw;
        if(cu-b>0)q.push(make_pair(cw,cu-b));
        if(cu+a<maxn)q.push(make_pair(max(cw,cu+a),cu+a));
    }
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    cin>>m>>a>>b;
    fnd();
    long long ans=0;
    int ed=min(m,max(a,b)<<1),st=0;
    for(int i=0;i<=ed;i++){
        if(mi[i]!=-1&&mi[i]<=ed){
            ans+=ed-mi[i]+1;
            st++;
        }
    }
    int g=gcd(a,b),fc=-1;
    for(int i=ed+1;i<=m;i++){
        if(i%g==0){
            fc=i;
            break;
        }
        ans+=st;
    }
    st++;
    if(fc==-1){
        cout<<ans;
        return 0;
    }
    long long lgt=0,len;
    lgt=(m/g)*g;
    len=(lgt-fc)/g;
    ans+=(long long)(g)*(((len+st+st-1)*len)>>1);
    for(int i=lgt;i<=m;i++)ans+=st+len;
    cout<<ans;
    return 0;
}