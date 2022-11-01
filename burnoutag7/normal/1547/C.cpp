#include<bits/stdc++.h>
using namespace std;

void mian(){
    int k,n,m;
    cin>>k>>n>>m;
    queue<int> a,b,r;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.emplace(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b.emplace(x);
    }
    while(!(a.empty()&&b.empty())){
        if(!a.empty()&&a.front()<=k){
            k+=a.front()==0;
            r.emplace(a.front());
            a.pop();
        }else if(!b.empty()&&b.front()<=k){
            k+=b.front()==0;
            r.emplace(b.front());
            b.pop();
        }else{
            cout<<"-1\n";
            return;
        }
    }
    while(!r.empty()){
        cout<<r.front()<<' ';
        r.pop();
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}