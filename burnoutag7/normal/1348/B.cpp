#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        set<int> st;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            st.insert(a[i]);
        }
        if(st.size()>k){
            cout<<-1<<'\n';
            continue;
        }
        vector<int> v;
        for(const int &x:st)v.emplace_back(x);
        while(v.size()<k)v.emplace_back(*st.begin());
        cout<<n*k<<'\n';
        for(int i=1;i<=n;i++){
            for(const int &x:v)cout<<x<<' ';
        }
        cout<<'\n';
    }

    return 0;
}