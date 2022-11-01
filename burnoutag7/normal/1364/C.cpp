#include<bits/stdc++.h>
using namespace std;

int n,cur;
int a[100005];
int b[100005];
stack<int> s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(b,-1,sizeof(b));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s.push(i);
        if(cur+s.size()<a[i]){
            cout<<-1<<endl;
            return 0;
        }
        while(cur<a[i]){
            b[s.top()]=cur++;
            s.pop();
        }
    }
    for(int i=1e6;!s.empty();i--){
        b[s.top()]=i;
        s.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;

    return 0;
}