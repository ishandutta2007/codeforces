#include <bits/stdc++.h>
using namespace std;
struct st{
    long long x,y,s,pos;
};
vector<st> v;
long long n,ans;
long long a,b,c,k[5];
long long x,y;
inline bool cmp(st a,st b){
    if (a.x!=b.x) return a.x<b.x;
    else if (a.y!=b.y) return a.y<b.y;
    else return a.s<b.s;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>k[1]>>k[2]>>k[3];
        sort(k+1,k+4);
        a=k[1]; b=k[2]; c=k[3];
        if (min(min(a,b),c)>ans){
            x=i;
            ans=min(min(a,b),c);
        }
        st t;
        t.x=a; t.y=b; t.s=c; t.pos=i;
        v.push_back(t);
        t.x=b; t.y=c; t.s=a;
        v.push_back(t);
        t.x=a; t.y=c; t.s=b;;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=1;i<v.size();++i){
        if (v[i].x==v[i-1].x && v[i].y==v[i-1].y && v[i].pos!=v[i-1].pos && min(min(v[i].x,v[i].y),v[i].s+v[i-1].s)>ans){
                ans=min(min(v[i].x,v[i].y),v[i].s+v[i-1].s);
                x=v[i].pos;
                y=v[i-1].pos;
        }
        if (min(min(v[i].x,v[i].y),v[i].s)>ans){
            ans=min(min(v[i].x,v[i].y),v[i].s);
            x=v[i].pos;
            y=0;
        }
    }
    if (y==0) cout<<1<<'\n'<<x;
    else cout<<2<<'\n'<<x<<" "<<y;
}