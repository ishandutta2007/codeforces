#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[105];
set<int> s;
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        s.clear();
        v.clear();
        for(int i=0;i<n<<1;i++){
            cin>>a[i];
            if(s.find(a[i])==s.end()){
                s.insert(a[i]);
                v.push_back(a[i]);
            }
        }
        for(int &x:v)cout<<x<<' ';
        cout<<endl;
    }

    return 0;
}