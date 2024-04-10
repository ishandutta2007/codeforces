#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map <int,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r,t;
        cin>>r;
        for(int j=0;j<r;j++){
            cin>>t;
            m[t]++;
        }
    }
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
        if(i->sc==n)cout<< (i->fr)<<" ";
    }
}