#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<long long>heap[3];
main(){
    long long k[3],x,an=0,start,now;
    int t[3],i,j,n;
    for(i=0;i<3;i++)cin>>k[i];
    for(i=0;i<3;i++)cin>>t[i];
    cin>>n;
    for(i=0;i<3;i++){
        for(j=0;j<k[i]&&j<n;j++)heap[i].push(-1);
    }
    while(n--){
        cin>>now;
        start=now;
        for(i=0;i<3;i++){
            x=-heap[i].top();
            heap[i].pop();
            now=max(x,now)+t[i];
            heap[i].push(-now);
        }
        an=max(an,now-start);
    }
    cout<<an<<endl;
}