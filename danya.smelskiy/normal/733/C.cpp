#include <bits/stdc++.h>
using namespace std;

int n,x,m;
vector<int> a,b;
vector<pair<int,char > > ans;
int kol;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        a.push_back(x);
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>x;
        b.push_back(x);
    }
    while (a.size() || b.size()) {
        if (a.size()==0 && b.size()==0) break;
        if (a.size()==0 || b.size()==0) {
            cout<<"NO";
            return 0;
        }
        if (a[0]==b[0]) {
            ++kol;
            a.erase(a.begin());
            b.erase(b.begin());
            continue;
        }
        int pos=-1,sum=0;
        for (int i=0;i<a.size();++i) {
            sum+=a[i];
            pos=i;
            if (sum>=b[0]) break;
        }
        if (sum!=b[0]) {
            cout<<"NO";
            return 0;
        }
        int pos2=0;
        for (int i=1;i<=pos;++i) {
            if (a[i]>=a[pos2] && (a[i]!=a[i-1] || (i<pos && a[i]!=a[i+1]))) pos2=i;
        }
        bool t=false;
        for (int i=0;i<=pos;++i)
        if (a[i]!=a[pos2]) {
            t=true;
            break;
        }
        if (t==false) {
            cout<<"NO";
            return 0;
        }
        while (pos) {
            if (pos2 && a[pos2]>a[pos2-1]) {
                a[pos2]+=a[pos2-1];
                ans.push_back(make_pair(kol+pos2+1,'L'));
                --pos2;
                a.erase(a.begin()+pos2-1);
            } else {
                a[pos2]+=a[pos2+1];
                ans.push_back(make_pair(kol+pos2+1,'R'));
                a.erase(a.begin()+pos2+1);
            }
            --pos;
        }
        ++kol;
        a.erase(a.begin());
        b.erase(b.begin());
    }
    cout<<"YES"<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}