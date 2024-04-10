#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    map<vector<int>,map<vector<int>,int>> m;
    long long ans=0;
    while(n--){
        int a;
        cin>>a;
        vector<int> p,b;
        for(int i=2;i*i<=a;i++)if(a%i==0){
            p.emplace_back(i);
            b.emplace_back(0);
            while(a%i==0){
                b.back()++;
                a/=i;
            }
            b.back()%=k;
            if(!b.back()){
                p.pop_back();
                b.pop_back();
            }
        }
        if(a>1){
            p.emplace_back(a);
            b.emplace_back(1);
        }
        vector<int> c;
        for(int x:b)c.emplace_back(k-x);
        ans+=m[p][c];
        m[p][b]++;
    }
    cout<<ans;

    return 0;
}