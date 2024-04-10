#include<bits/stdc++.h>
using namespace std;

int n,a[505][505],lf[1005],slr[1005],mv[1005];
vector<pair<int,int>> ansv;
vector<int> q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        lf[i]=i;
        slr[i]=a[i][i];
        q.emplace_back(i);
        mv[i]=114514;
        for(int j=1;j<=n;j++)if(i!=j){
            mv[i]=min(mv[i],a[i][j]);
        }
    }
    while(q.size()>1){
        int x=-1,vx=114514;
        for(int i=0;i<q.size();i++){
            if(vx>mv[q[i]]){
                x=i;
                vx=mv[q[i]];
            }
        }
        vx=q[x];
        q.erase(q.begin()+x);
        x=vx;
        vector<int> y(1,0);
        for(int i=1;i<q.size();i++){
            if(a[lf[q[i]]][lf[x]]<a[lf[q[y.front()]]][lf[x]]){
                y.clear();
                y.emplace_back(i);
            }else if(a[lf[q[i]]][lf[x]]==a[lf[q[y.front()]]][lf[x]]){
                y.emplace_back(i);
            }
        }
        ++n;
        lf[n]=lf[x];
        slr[n]=a[lf[q[y.front()]]][lf[x]];
        for(int i=0;i<y.size();i++){
            ansv.emplace_back(q[y[i]],n);
        }
        ansv.emplace_back(x,n);
        for(int i=y.size()-1;i>=0;i--)q.erase(q.begin()+y[i]);
        mv[n]=114514;
        for(int cc:q)mv[n]=min(mv[n],a[lf[cc]][lf[n]]);
        q.emplace_back(n);
    }
    cout<<n<<'\n';
    for(int i=1;i<=n;i++)cout<<slr[i]<<' ';
    cout<<'\n'<<n<<'\n';
    for(pair<int,int> &p:ansv)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}