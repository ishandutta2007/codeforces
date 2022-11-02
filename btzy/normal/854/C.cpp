#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct firstcomp{
    bool operator()(pair<unsigned, unsigned>& a, pair<unsigned, unsigned>& b){
        return a.first<b.first;
    }
};
unsigned arr[300000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n,k;
    cin>>n>>k;
    priority_queue<pair<unsigned,unsigned>,vector<pair<unsigned,unsigned>>,firstcomp> pq;
    unsigned i=0;
    for(;i<k;++i){
        unsigned x;
        cin>>x;
        pq.emplace(x,i);
    }
    unsigned long long pay=0;
    for(;i<n;++i){
        unsigned x;
        cin>>x;
        pq.emplace(x,i);
        auto& tmp=pq.top();
        arr[tmp.second]=i;
        pay+=static_cast<unsigned long long>(i-tmp.second)*tmp.first;
        pq.pop();
    }
    for(;i<n+k;++i){
        auto& tmp=pq.top();
        arr[tmp.second]=i;
        pay+=static_cast<unsigned long long>(i-tmp.second)*tmp.first;
        pq.pop();
    }
    cout<<pay<<endl;
    for(unsigned i=0;i<n;++i){
        if(i>0)cout<<' ';
        cout<<arr[i]+1;
    }
}