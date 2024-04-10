#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    vc<int> v[n+1];
    set<int> s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].pb(i);
        s.insert(a[i]);
    }
    int z=1;
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        int c=*it;
        while(!v[c].empty()){
            int d=n-c;
            while(d!=0){
                if(v[c].empty())goto fail;
                a[v[c][v[c].size()-1]]=z;
                v[c].pop_back();
                d--;
            }
            if(z>n)goto fail;
            z++;
        }
    }
    cout<<"Possible\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
    fail: cout<<"Impossible";
}