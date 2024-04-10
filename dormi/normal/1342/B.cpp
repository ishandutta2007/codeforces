#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        set<char> chs;
        for(char x:a){
            chs.insert(x);
        }
        if(sz(chs)==1){
            cout<<a<<"\n";
        }
        else{
            for(int i=0;i<2*sz(a);i++){
                cout<<(i%2?'1':'0');
            }
            cout<<"\n";
        }
    }
    return 0;
}