#include<bits/stdc++.h>
using namespace std;

int n,q;
int pre[200005][26];
char s[200005];
vector<pair<int,int> > v[26];

bool solve(int l,int r){
    int cnt[26],sum=0;
    int typ=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<26;i++){
        cnt[i]=pre[r][i]-pre[l-1][i];
        sum+=cnt[i];
        typ+=(bool)cnt[i];
    }
    if(typ==1){
        return r-l==0;
    }
    if(typ==2){
        vector<pair<int,int> > &vec=v[s[l]-'a'];
        int pos=lower_bound(vec.begin(),vec.end(),make_pair(r+1,-1))-vec.begin();
        pos--;
        if(vec[pos].second>=r){
            return false;
        }else{
            return true;
        }
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    cin>>q;
    for(int i=1;i<=n;i++){
        memcpy(pre[i],pre[i-1],sizeof(pre[i]));
        pre[i][s[i]-'a']++;
        vector<pair<int,int> > &vec=v[s[i]-'a'];
        if(s[i]!=s[i-1])vec.push_back(make_pair(i,i));
        else vec[vec.size()-1].second=i;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(solve(l,r)?"Yes":"No")<<endl;
    }

    return 0;
}