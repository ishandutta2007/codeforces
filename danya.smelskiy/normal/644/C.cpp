#include <bits/stdc++.h>
using namespace std;


int n;
string s;
vector<pair<string,string> > v;
vector<string> q;
map<string,bool> used;
map<string,string> ans;
vector<string> last;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s;
        int j=7;
        string nm="";
        for (;j<s.size() && s[j]!='/';++j) {
            nm+=s[j];
        }
        string st="";
        if (j==s.size()) st="#.DANYA.#";
        ++j;
        for (;j<s.size();++j)
            st+=s[j];
        st+="#";
        v.push_back(make_pair(st,nm));
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) {
        if (used[v[i].second]==false) {
            used[v[i].second]=true;
            q.push_back(v[i].second);
        }
        if (i==0 || !(v[i].first==v[i-1].first && v[i].second==v[i-1].second)) {
            ans[v[i].second]+=v[i].first;
        }
    }
    v.clear();
    for (int i=0;i<q.size();++i) {
        v.push_back(make_pair(ans[q[i]],q[i]));
    }
    int lastkol=0;
    int kol=0;
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) {
        //cout<<v[i].first<<" "<<v[i].second<<'\n';
        ++lastkol;
        if (i==v.size()-1 || (v[i].first!=v[i+1].first)){
            if (lastkol>1) ++kol;
                lastkol=0;
        }
    }
    cout<<kol<<'\n';
    for (int i=0;i<v.size();++i) {
        last.push_back(v[i].second);
        if (i==v.size()-1 || (v[i].first!=v[i+1].first)){
            if (last.size()>1) {
            for (int j=0;j<last.size();++j)
                cout<<"http://"<<last[j]<<" ";
            cout<<'\n';
            }
            last.clear();
        }
    }
}