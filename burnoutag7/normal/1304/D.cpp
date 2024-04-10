#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005];
int ans[200005];
vector<pair<pair<int,int>,char> > seg;

void precalc(){
    for(int l=1,r;l<n;){
        r=l;
        while(r<n&&s[r+1]==s[l])r++;
        seg.push_back(make_pair(make_pair(l,r),s[l]));
        l=r+1;
    }
}

void shortest(){
    int cur=n;
    for(int i=0;i<seg.size();i++){
        if(seg[i].second=='<'){
            for(int j=seg[i].first.second;j>=seg[i].first.first;j--)ans[j]=cur--;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]==-1)ans[i]=cur--;
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

void longest(){
    int cur=1;
    for(int i=0;i<seg.size();i++){
        if(seg[i].second=='>'){
            for(int j=seg[i].first.second;j>=seg[i].first.first;j--)ans[j]=cur++;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]==-1)ans[i]=cur++;
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

void solve(){
    cin>>n>>s+1;
    seg.clear();
    precalc();
    for(int i=0;i<n;i++)ans[i]=-1;
    shortest();
    for(int i=0;i<n;i++)ans[i]=-1;
    longest();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}