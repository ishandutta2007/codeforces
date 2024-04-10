#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q,cnt;
ll tot;
int a[200005];
map<int,int> mp;
vector<int> p[200005];
bool onshelf[200005];

void ext(int x,vector<int> &ps){
    if(x==1){
        return;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ps.push_back(i);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ps.push_back(x);
}

void puton(int x){
    int res=cnt;
    for(int s=1;s<(1<<p[x].size());s++){
        int mt=1,bts=0;
        for(int i=0;i<p[x].size();i++){
            if(s&(1<<i)){
                mt*=p[x][i];
                bts++;
            }
        }
        if(bts&1){
            res-=mp[mt];
        }else{
            res+=mp[mt];
        }
        mp[mt]++;
    }
    tot+=res;
}

void takeoff(int x){
    int res=cnt;
    for(int s=1;s<(1<<p[x].size());s++){
        int mt=1,bts=0;
        for(int i=0;i<p[x].size();i++){
            if(s&(1<<i)){
                mt*=p[x][i];
                bts++;
            }
        }
        mp[mt]--;
        if(bts&1){
            res-=mp[mt];
        }else{
            res+=mp[mt];
        }
    }
    tot-=res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ext(a[i],p[i]);
    }
    while(q--){
        int x;cin>>x;
        if(onshelf[x]){
            cnt--;
            takeoff(x);
        }else{
            puton(x);
            cnt++;
        }
        onshelf[x]^=1;
        cout<<tot<<endl;
    }

    return 0;
}