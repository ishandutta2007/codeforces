#include<bits/stdc++.h>
using namespace std;

int n,a[105];

void mian(){
    cin>>n;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)cin>>a[i],pq.emplace(a[i]);
    while(!pq.empty()){
        int t=pq.top();
        pq.pop();
        if(pq.empty()){
            cout<<"T\n";
            return;
        }
        int hl=pq.top();
        pq.pop();
        t--;
        hl--;
        if(t)pq.emplace(t);
        if(hl)pq.emplace(hl);
    }
    cout<<"HL\n";
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