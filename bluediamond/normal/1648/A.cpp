#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

int solve(vector<int> v){
        int sol=0;

        int n=(int)v.size();
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
                sol-=v[i]*(n-i-1);

        }

        for(int i=0;i<n;i++){
                sol+=v[i]*i;
        }

        return sol;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

     ///   freopen ("input","r",stdin);

        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int> (m));
        vector<vector<pair<int,int>>> where((int)1e5+7);
        for(auto&v:a){
                for(auto&x:v){
                        cin>>x;
                }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        where[a[i][j]].push_back({i,j});
                }
        }


        int sol=0;
        for(auto&v:where){
                vector<int> a,b;
                for(auto&it:v){
                        a.push_back(it.first);
                        b.push_back(it.second);
                }
                sol+=solve(a);
                sol+=solve(b);
        }
        cout<<sol;


}