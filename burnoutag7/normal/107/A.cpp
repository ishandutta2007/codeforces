#include<bits/stdc++.h>
using namespace std;

struct OUT{
    int tank;
    int tap;
    int diameter;
};

pair<int,int> f[1005],s[1005];
int n,p;
int ans;
vector<OUT> out;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<1005;i++){
        f[i]=make_pair(-1,-1);
        s[i]=make_pair(-1,-1);
    }
    cin>>n>>p;
    for(int i=0;i<p;i++){
        int a,b,d;
        cin>>a>>b>>d;
        f[b]=make_pair(a,d);
        s[a]=make_pair(b,d);
    }
    for(int i=1;i<=n;i++){
        if(f[i].first==-1&&s[i].first!=-1){
            int cur=i,d=1e9;
            while(s[cur].first!=-1){
                d=min(d,s[cur].second);
                cur=s[cur].first;
            }
            OUT now;
            now.tank=i;
            now.tap=cur;
            now.diameter=d;
            out.push_back(now);
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<out.size();i++){
        cout<<out[i].tank<<' '<<out[i].tap<<' '<<out[i].diameter<<endl;
    }

    return 0;
}