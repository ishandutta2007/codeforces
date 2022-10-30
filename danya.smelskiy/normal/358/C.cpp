#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
bool used[100005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int i=1;
    while (i<=n) {
        int j=i;
        while (j<=n && a[j]) ++j;
        --j;
        if (j<i) {
            cout<<"0\n";
            ++i;
            continue;
        }
        vector<pair<int,int> > v;
        for (int k=i;k<=j;++k)
            v.push_back(make_pair(a[k],k));
        sort(v.begin(),v.end());
        for (int k=v.size()-1;k>=max(0,(int)v.size()-3);--k) {
            used[v[k].second]=true;
        }
        int last=0;
        for (int k=i;k<=j;++k) {
            if (used[k]) {
                if (last==0) cout<<"pushStack"<<'\n';
                else if (last==1) cout<<"pushQueue"<<'\n';
                else cout<<"pushFront"<<'\n';
                ++last;
                continue;
            }
            cout<<"pushBack"<<'\n';
        }
        if (j<n && a[j+1]==0) {
        cout<<last;
        if (!last) cout<<'\n';
        else {
            cout<<" popStack";
            if (last>1) cout<<" popQueue";
            if (last>2) cout<<" popFront";
            cout<<'\n';
        }
        }
        i=j+2;
    }

}