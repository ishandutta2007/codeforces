#include <bits/stdc++.h>
using namespace std;




int n;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n<=2) cout<<"No";
    else {
        cout<<"Yes"<<'\n';
        vector<int> v1,v2;
        if (n%2==0) {
            v1.push_back(1);
            v1.push_back(3);
            v2.push_back(2);
            for (int i=4;i<=n;++i)
                if (i&1) v1.push_back(i);
                else v2.push_back(i);
        } else {
            for (int i=1;i<=n;++i)
                if (i<=(n+1)/2) v1.push_back(i);
                else v2.push_back(i);
        }
        cout<<v1.size()<<" ";
        for (int i=0;i<v1.size();++i)
            cout<<v1[i]<<" ";
        cout<<'\n';
        cout<<v2.size()<<" ";
        for (int i=0;i<v2.size();++i)
            cout<<v2[i]<<" ";
    }
}