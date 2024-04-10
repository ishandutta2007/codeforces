#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005],c[100005],req2[100005],done;
set<int> req1[100005];
vector<int> ans;

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        req1[i].clear();
    }
    memset(req2+1,-1,n<<2);
    done=-1;
    ans.clear();
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]!=b[i])req1[b[i]].insert(i);
        else req2[b[i]]=i;
    }
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=m;i>=1;i--){
        if(!req1[c[i]].empty()){
            ans.push_back(*req1[c[i]].begin());
            req1[c[i]].erase(req1[c[i]].begin());
            done=ans.back();
        }else if(req2[c[i]]!=-1){
            ans.push_back(req2[c[i]]);
            done=req2[c[i]];
        }else if(done!=-1){
            ans.push_back(done);
        }else{
            cout<<"NO\n";
            return;
        }
    }
    for(int i=1;i<=n;i++)if(!req1[i].empty()){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    reverse(ans.begin(),ans.end());
    for(int x:ans)cout<<x<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}