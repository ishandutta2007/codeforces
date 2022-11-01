#include<bits/stdc++.h>
using namespace std;

inline int cmp(const int &a,const int &b){
    return (a>b)-(a<b);
}

int n,p;
int a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<int> v;
        v.emplace_back(a[1]);
        v.emplace_back(a[2]);
        p=cmp(a[1],a[2]);
        for(int i=3;i<=n;i++){
            if(cmp(a[i-1],a[i])==p){
                v.pop_back();
            }
            v.emplace_back(a[i]);
            p=cmp(a[i-1],a[i]);
        }
        cout<<v.size()<<endl;
        for(int &x:v)cout<<x<<' ';
        cout<<endl;
    }

    return 0;
}