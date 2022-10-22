#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define F first
#define S second
typedef long long int ll;
const int MAXN=2e5+10;
bool flag[MAXN];
vector<int> adj[MAXN];
int ar[MAXN];
vector<pair<int,int> > ans;
int n,m;
void dfs(int v,vector<int> *tc,int cnt){
    flag[v]=1;
    ar[v]=cnt;
    tc->push_back(v);
    for(int i : adj[v]){
        if(!flag[i]) dfs(i,tc,cnt),ans.push_back({v,i});
    }
}
int main()
{
    int s,t,ds,dt;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    cin >> s >> t >> ds >> dt;
    s--;
    t--;
    vector<vector<int> > c;
    flag[s]=1;
    flag[t]=1;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(flag[i]) continue;
        vector<int> tc;
        dfs(i,&tc,cnt++);
        c.push_back(tc);
    }
    bool bs[cnt],bt[cnt];
    int bsh[cnt],bth[cnt];
    fill(bs,bs+cnt,false);
    fill(bt,bt+cnt,false);
    bool p=0;
    for(int i : adj[s]){
        if(i==t){
            p=1;
            continue;
        }
        bs[ar[i]]=1;
        bsh[ar[i]]=i;
    }
    for(int i : adj[t]){
        if(i==s){
            p=1;
            continue;
        }
        bt[ar[i]]=1;
        bth[ar[i]]=i;
    }
    vector<int> es,et,bh;
    for(int i=0; i<cnt; i++){
        if(!bs[i] && !bt[i]) return cout<<"No\n",0;
        else if(bs[i] && bt[i]) bh.push_back(i);
        else if(bs[i]) es.push_back(i);
        else et.push_back(i);
    }
    for(int i : es){
        ans.push_back({s,bsh[i]});
        ds--;
    }
    for(int i : et){
        ans.push_back({t,bth[i]});
        dt--;
    }
    if(bh.size()==0 && !p) return cout<<"No\n",0;
    else if(bh.size()==0) ans.push_back({s,t}),dt--,ds--;
    else{
        int k=bh[0];
        ans.push_back({s,bsh[k]});
        ans.push_back({t,bth[k]});
        bh.erase(bh.begin());
        ds--;
        dt--;
        for(int i : bh){
            if(ds<=0 && dt<=0) return cout<<"No\n",0;
            if(ds>0){
                ds--;
                ans.push_back({s,bsh[i]});
            }else ans.push_back({t,bth[i]}),dt--;
        }
    }
    if(dt<0 || ds<0) return cout<<"No\n",0;
    cout << "Yes\n";
    for(pair<int,int> i : ans){
        cout << i.F+1 << ' ' << i.S+1 << '\n';
    }
	return 0;
}