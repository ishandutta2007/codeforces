#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105],b[105];
set<int> s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
        s.insert(b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s.find(a[i]+b[j])==s.end()){
                cout<<a[i]<<' '<<b[j]<<endl;
                return 0;
            }
        }
    }

    return 0;
}