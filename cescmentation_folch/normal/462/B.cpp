#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef unsigned long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;

bool xec(int x, int y){
    if(x > y) return true;
    return false;
}

int main(){
    ll n,m;
    string s;
    cin>>n>>m;
    VI G(26,0);
    for(int i = 0;i < n;++i){
        char a;
        cin>>a;
        ++G[(a-'A')];
    }
    sort(G.begin(),G.end(),xec);
    ll ky = 0;
    for(int i = 0;i < 26;++i){
        if(G[i] >= m){
            ky += m*m;
            break;
        }
        else{
            ky += G[i]*G[i];
            m -= G[i];
        }
    }
    cout<<ky<<endl;
}