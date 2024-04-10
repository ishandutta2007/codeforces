#include <bits/stdc++.h>
using namespace std;
string s,ss;
int p[5005];
vector<pair<int,int> > ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    string sp=s;
    reverse(sp.begin(),sp.end());
    while (ss.size()) {
        string sk=ss+"#"+s;
        for (int i=1;i<sk.size();++i) {
            int j=p[i-1];
            while (j && sk[j]!=sk[i]) j=p[j-1];
            if (sk[j]==sk[i]) ++j;
            p[i]=j;
        }
        int maxl=-1;
        int ll=-1,rr=-1;
        for (int i=ss.size()+1;i<sk.size();++i)
            if (p[i]>maxl) {
                maxl=p[i];
                ll=i-ss.size();
                rr=ll-maxl+1;
                swap(ll,rr);
            }
        sk=ss+"#"+sp;
        for (int i=1;i<sk.size();++i) {
            int j=p[i-1];
            while (j && sk[j]!=sk[i]) j=p[j-1];
            if (sk[j]==sk[i]) ++j;
            p[i]=j;
        }
        for (int i=ss.size()+1;i<sk.size();++i)
            if (p[i]>maxl) {
                maxl=p[i];
                ll=i-ss.size();
                ll=s.size()-ll+1;
                rr=ll+maxl-1;
                swap(ll,rr);
            }
        if (maxl<=0) {
            cout<<"-1";
            return 0;
        }
        ans.push_back(make_pair(ll,rr));
        if (ll>rr) swap(ll,rr);
        string nk="";
        for (int i=maxl+1;i<=ss.size();++i)
            nk+=ss[i-1];
        ss=nk;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}