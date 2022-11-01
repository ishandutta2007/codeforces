//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    priority_queue<int> m,d;
    for(int i=0;i<n<<1;i++){
        int x,y;
        cin>>x>>y;
        if(x==0)m.emplace(abs(y));
        else d.emplace(abs(x));
    }
    double ans=0;
    while(n--){
        ans+=sqrt((long long)m.top()*m.top()+(long long)d.top()*d.top());
        m.pop();
        d.pop();
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout<<fixed<<setprecision(15);
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}