#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=1000;
vector<int> v; // starts with fix, ends with increase(if last increased) or fix(if last decreased)
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    bool isincrease=true;
    int ans=0;
    v.push_back(0);
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(isincrease){
            v.push_back(x);
        }
        else {
            while(!v.empty()){
                if(v.back()>x){
                    ans+=x;
                    v.back()-=x;
                    v.push_back(1);
                    break;
                }
                else {
                    ans+=v.back();
                    x-=v.back();
                    v.pop_back();
                    ans+=v.back();
                    if(x==0){
                        v.back()++;
                        break;
                    }
                    else{
                        v.pop_back();
                    }
                }
            }
            if(v.empty()){
                v.push_back(0);
            }
        }
        isincrease=!isincrease;
    }
    cout<<ans<<'\n';
}