#include<bits/stdc++.h>
using namespace std;

int n,k,id;
queue<int> q;
set<int> t;
stack<int> s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>id;
        if(t.find(id)==t.end()){
            if(q.size()==k){
                t.erase(q.front());
                q.pop();
            }
            q.push(id);
            t.insert(id);
        }
    }
    cout<<q.size()<<endl;
    while(q.size()){
        s.push(q.front());
        q.pop();
    }
    while(s.size()){
        cout<<s.top()<<' ';
        s.pop();
    }

    return 0;
}